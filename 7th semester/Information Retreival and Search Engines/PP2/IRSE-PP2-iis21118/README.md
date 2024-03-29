# Πρόγραμμα Ανάλυσης Συναισθήματος σε Python

Το συγκεκριμένο python πρόγραμμα πραγματοποιεί ανάλυση συναισθήματος σε κριτικές ταινιών χρησιμοποιώντας το `polarity_dataset_v2.0`. Το σύνολο δεδομένων αποτελείται από αρχεία κειμένου που κατηγοριοποιούνται ως θετικές ή αρνητικές κριτικές. Η ανάλυση συναισθήματος πραγματοποιείται χρησιμοποιώντας μια προσέγγιση ταξινόμησης κειμένου, συγκεκριμένα με ταξινομητές Multinomial Naive Bayes και Bernoulli Naive Bayes.

## Εγκατάσταση

### Προαπαιτούμενα
- Python
- NLTK (Εργαλεία Επεξεργασίας Φυσικής Γλώσσας)
- Scikit-learn

### Εγκατάσταση
1. Βεβαιωθείτε ότι έχετε εγκατεστημένη την Python.
2. Εγκαταστήστε τα απαιτούμενα dependencies χρησιμοποιώντας την παρακάτω εντολή:
    ```bash
    pip install nltk scikit-learn
    ```
3. Κατεβάστε τα εργαλεία του NLTK (σβήνοντας τα σχόλια στον κώδικα):
    ```python
    import nltk
    nltk.download('punkt')
    nltk.download('stopwords')
    nltk.download('wordnet')
    ```

## Χρήση

1. **Σύνολο Δεδομένων:**
   Το πρόγραμμα υποθέτει ότι το αρχείο `review_polarity.tar.gz` βρίσκεται ήδη στον φάκελο του project. Σε περίπτωση που αυτό δεν ισχύει, απλά αλλάξτε το path με το σωστό path του αρχείου στη μεταβλητή `tar_gz_file_path`.

2. **Εκτέλεση του Προγράμματος:**
   Το πρόγραμμα θα σας ζητήσει να επιλέξετε έναν classifier:
   - Εισαγάγετε `1` για τον Multinomial Naive Bayes
   - Εισαγάγετε `2` για τον Bernoulli Naive Bayes
   - Εισαγάγετε `exit` για να τερματίσετε το πρόγραμμα.

3. **Προβολή Αποτελεσμάτων:**
   Το πρόγραμμα θα εμφανίσει τα αποτελέσματα για τον επιλεγμένο classifier, και πιο συγκεκριμένα θα δείξει accuracy, precision, recall και το confusion matrix. 

## Προεπεξεργασία

Το πρόγραμμα εκτελεί κάποια βήματα προεπεξεργασίας τα οποία είναι:
- Text lowercasing
- Tokenization
- Αφαίρεση stopwords
- Lemmatization
- Stemming
- N-gram generation (προαιρετικό)

Αυτά τα βήματα προεπεξεργασίας ενισχύουν την ποιότητα των δεδομένων κειμένου για την ταξινόμηση.

## Φόρτωση Δεδομένων

Τα αρχεία κειμένου φορτώνονται από τους φακέλους `pos` και `neg`. Το κάθε αρχείο υποβάλλεται σε προεπεξεργασία, και του αναθέτονται οι αντίστοιχες ετικέτες (θετικές ή αρνητικές).

## Κατηγοριοποίηση

Το πρόγραμμα επιτρέπει την επιλογή ανάμεσα σε classifiers Multinomial Naive Bayes και Bernoulli Naive Bayes. Χρησιμοποιεί τη βιβλιοθήκη Scikit-learn για τη δημιουργία του περιβάλλοντος ταξινόμησης, τη διανυσματοποίηση των δεδομένων κειμένου και την αξιολόγηση του μοντέλου χρησιμοποιώντας 5-fold cross validation.