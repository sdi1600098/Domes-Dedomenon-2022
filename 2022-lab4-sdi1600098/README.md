# Lab4

Εργαστήριο 4:  B+-δένδρα
Στο εργαστήριο αυτό θα υλοποιήσουμε τη δομή των Β+-δένδρων που συζητήσαμε στην Ενότητα διαλέξεων 14.  Ο κώδικας που θα χρησιμοποιήσουμε προέρχεται από το Κεφάλαιο 16.3 του βιβλίου του Robert Sedgewick “Αλγόριθμοι σε C” που σας έχουμε προτείνει από τον Εύδοξο. Προσοχή: στο βιβλίο η δομή αναφέρεται σαν Β-δένδρο, όμως είναι Β+-δένδρο με βάση τη δική μας παρουσίαση και τις διαφάνειες της Ενότητας 14 (χωρίς όμως να έχουμε οργάνωση των εξωτερικών κόμβων σε μια ταξινομημένη συνδεδεμένη λίστα). 

Ο κώδικας κάνει τα εξής:

•	Program 16.1. Ορίζει τις δομές που χρειαζόμαστε για να υλοποιήσουμε Β+-δένδρα και αρχικοποιεί αυτές τις δομές.

•	Program 16.2. Υλοποιεί τη πράξη της αναζήτησης ενός κλειδιού.

•	Program 16.3 Υλοποιεί την πράξη της εισαγωγής ενός στοιχείου στο δένδρο.

Στο εργαστήριο αυτό έχετε να κάνετε τα εξής:

1. Μελετήστε προσεκτικά το σχετικό κεφάλαιο από το βιβλίο, καθώς και τον κώδικα και κατανοήστε τη λειτουργία του. 

2. Γράψτε μια συνάρτηση main η οποία θα παρουσιάζει τη λειτουργία των δύο συναρτήσεων που σας δίνουμε. Η main αρχικά θα διαβάζει  στοιχεία από την είσοδο και θα τα βάζει στο δένδρο. Για να κάνουμε την πληροφορία που αποθηκεύεται στο δένδρο ενδιαφέρουσα, κάθε στοιχείο θα αποτελείται από τρία μέρη: το κλειδί, που θα είναι ο αριθμός μητρώου ενός φοιτητή/φοιτήτριας (ακέραιος μεγαλύτερος ή ίσος του 1), το όνομα του/της και το επώνυμο του/της. Μετά η main θα ψάχνει για κλειδιά που δίνονται στην είσοδο και θα πληροφορεί τον χρήστη αν υπάρχουν ή όχι στο δένδρο, δίνοντας ταυτόχρονα την αντίστοιχη πληροφορία για το κλειδί (όνομα και επώνυμο). Στο ερώτημα αυτό φυσικά θα χρειαστεί (i) να ορίσετε κατάλληλα τους τύπους Key και Item (δείτε τα typedefs και τα macros στις διαφάνειες 21-22 της Ενότητας 10) και (ii) να αλλάξετε τις συναρτήσεις STInsert και STSeach. Οι αλλαγές σας θα πρέπει να είναι «χειρουργικές» δηλ. θα πρέπει να κάνετε τις ελάχιστες δυνατές αλλαγές που θα σας δώσουν τη λειτουργικότητα που θέλετε.

3. Γράψτε μια αναδρομική συνάρτηση void NaturalOrder() η οποία θα εκτυπώνει όλα τα κλειδιά του δένδρου με τη φυσική τους διάταξη (σε αύξουσα σειρά) μαζί με την πληροφορία που αποθηκεύουν. Παρουσιάστε τη λειτουργία της συνάρτησης γράφοντας κατάλληλο κώδικα στη main.

4. Γράψτε δύο αναδρομικές συναρτήσεις Item FindMin() και Item FindMax() οι οποίες θα βρίσκουν και θα επιστρέφουν το στοιχείο με το μικρότερο και το μεγαλύτερο κλειδί αντίστοιχα στο δένδρο. Παρουσιάστε τη λειτουργία της συνάρτησης γράφοντας κατάλληλο κώδικα στη main.

Ο κώδικας για τα ερωτήματα 2,3,4 που θα παραδώσετε θα πρέπει να έχει οργανωθεί σαν ένα module της C με βάση όσα έχουμε συζητήσει στις διαλέξεις μας (δεν χρειάζεται να έχετε φτιάξει makefiles).
