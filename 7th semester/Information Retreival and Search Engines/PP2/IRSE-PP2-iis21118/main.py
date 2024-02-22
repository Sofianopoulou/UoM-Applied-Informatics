# Text Classification Python Program
# Sentiment Analysis on text files of movie reviews (polarity_dataset_v2.0) which are either positive or negative
# Sofianopoulou Apostolia Maria - iis21118

import tarfile
import os
# import nltk
from nltk.corpus import stopwords
from nltk.util import ngrams
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.model_selection import cross_val_predict, StratifiedKFold
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score

# Download NLTK resources (you only need to run this once)
# nltk.download('punkt')
# nltk.download('stopwords')
# nltk.download('wordnet')

# The "review_polarity.tar.gz" file is already inside the project folder
tar_gz_file_path = './review_polarity.tar.gz'  # Folder to unzip
extract_folder = 'extracted_data'  # Where to unzip it


# Extract data from tar.gz zip file
def extract_tar_gz(tar_gz_file, extract_data):
    with tarfile.open(tar_gz_file, 'r:gz') as tar:
        tar.extractall(extract_data)


# Read content of file with given path
def read_file_content(file_path):
    with open(file_path, 'r', encoding='latin-1') as file:
        content = file.read()
    return content


# Extract the tar.gz file
extract_tar_gz(tar_gz_file_path, extract_folder)


# Read and print the content of a sample file
# sample_file_path = os.path.join(extract_folder, 'txt_sentoken/pos/cv000_29590.txt')
# sample_content = read_file_content(sample_file_path)
# print(sample_content)


# ------------------------- PREPROCESSING DATA -------------------------
def preprocess_text(text, generate_ngrams=False, apply_case_transform=True, lemmatize=True, n=3):
    # Tokenization
    tokens = word_tokenize(text)

    # Filter stopwords
    stop_words = set(stopwords.words('english'))
    tokens = [word for word in tokens if word.lower() not in stop_words]

    # Generate n-grams
    if generate_ngrams:
        n_grams = list(ngrams(tokens, n))
        # Combine tokens and n-grams
        tokens = tokens + [' '.join(gram) for gram in n_grams]

    # Stemming
    stemmer = PorterStemmer()
    tokens = [stemmer.stem(word) for word in tokens]

    # Transform case
    if apply_case_transform:
        tokens = [word.lower() for word in tokens]

    # Lemmatization
    if lemmatize:
        lemmatizer = WordNetLemmatizer()
        tokens = [lemmatizer.lemmatize(word) for word in tokens]

    # Reconstruct the preprocessed text
    preprocessed_text = ' '.join(tokens)

    return preprocessed_text


# ------------------------- DATA LOADING -------------------------
# Function to preprocess all the given text files inside pos and neg folders
def load_data(directory, preprocess_func):
    texts = []
    labels = []
    for label in ['pos', 'neg']:
        path = os.path.join(directory, label)
        for filename in os.listdir(path):
            with open(os.path.join(path, filename), 'r', encoding='latin-1') as file:
                content = file.read()
                preprocessed_content = preprocess_func(content)
                texts.append(preprocessed_content)
            labels.append(label)
    return texts, labels


# ------------------------- TRAINING AND EVALUATION -------------------------
# Function to train and evaluate a classifier
def train_and_evaluate_classifier(classifier, x, y):
    # Perform 5-fold cross-validation
    skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)
    predicted = cross_val_predict(classifier, x, y, cv=skf)

    # Calculate evaluation metrics
    accuracy = accuracy_score(y, predicted)
    precision = precision_score(y, predicted, average='weighted')
    recall = recall_score(y, predicted, average='weighted')
    conf_matrix = confusion_matrix(y, predicted)

    return accuracy, precision, recall, conf_matrix


# Function to display the confusion matrix in a tabular format
def display_confusion_matrix(conf_matrix, labels):
    max_label_len = max(len(label) for label in labels)  # Find the maximum length of labels

    # Print headers
    print(f"{max_label_len * ' '}  {' '.join(labels)}")
    for i, row_label in enumerate(labels):
        # Print each row with label and values
        row_values = ' '.join(f"{val:>{max_label_len}}" for val in conf_matrix[i, :])
        print(f"{row_label:>{max_label_len}} {row_values}")


# Main function
def main():
    while True:
        # Load data from 'pos' and 'neg' folders
        data_folder = os.path.join(extract_folder, 'txt_sentoken')
        texts, labels = load_data(data_folder, preprocess_text)

        # Apply the preprocessing function to all texts
        preprocessed_texts = [preprocess_text(text) for text in texts]

        # Print the preprocessed content of a sample file to check if preprocessing is adapted
        # sample_index = 0
        # print(f"\nSample preprocessed content ({labels[sample_index]}):")
        # print(preprocessed_texts[sample_index])

        # Encode labels
        label_encoder = LabelEncoder()
        y = label_encoder.fit_transform(labels)

        # Choose classifier based on user input
        print("Choose classifier:")
        print("1. Multinomial Naive Bayes")
        print("2. Bernoulli Naive Bayes")
        print("Enter 'exit' to end the program.")

        user_choice = input("Enter 1 or 2: ")

        if user_choice.lower() == 'exit':
            print("Exiting the program.")
            break
        elif user_choice == '1':
            vectorizer = CountVectorizer(binary=False)  # Term Occurrences
            classifier = make_pipeline(MultinomialNB())
            classifier_type = 'Multinomial'
        elif user_choice == '2':
            vectorizer = CountVectorizer(binary=True)  # Binary Term Occurrences
            classifier = make_pipeline(BernoulliNB())
            classifier_type = 'Bernoulli'
        else:
            print("Invalid choice. Please enter 1 or 2.")
            continue

        # Vectorize the text data using the chosen vectorizer
        x = vectorizer.fit_transform(preprocessed_texts)

        # Train and evaluate the classifier
        accuracy, precision, recall, conf_matrix = train_and_evaluate_classifier(classifier, x, y)

        # Display results
        print(f"\nResults for {classifier_type} Naive Bayes Classifier:")
        print("Accuracy: {:.2%}".format(accuracy))
        print("Weighted Mean Precision: {:.2%}".format(precision))
        print("Weighted Mean Recall: {:.2%}".format(recall))
        print("\nConfusion Matrix:")
        display_confusion_matrix(conf_matrix, label_encoder.classes_)
        print("\n-----------------------------------\n")


if __name__ == "__main__":
    main()
