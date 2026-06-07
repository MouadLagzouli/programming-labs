import java.util.ArrayList;

public class Compte implements Affichable {
    private String nom;
    private String numCompte;
    private double solde;
    private ArrayList<Transaction> historique;

    public Compte(String nom, String numCompte, double soldeInitial) {
        Validation.verifierNonVide(nom, "Le nom ne doit pas être vide.");
        Validation.verifierNonVide(numCompte, "Le numéro de compte ne doit pas être vide.");

       this.nom = nom.trim();
        this.numCompte = numCompte.trim();
        this.solde = soldeInitial;
        this.historique = new ArrayList<>();
    }

    public String getNom() { return nom; }
    public void setNom(String nom) {
        Validation.verifierNonVide(nom, "Le nom ne doit pas être vide.");
        this.nom = nom.trim();
    }

    public String getNumCompte() { return numCompte; }
    public void setNumCompte(String numCompte) {
        Validation.verifierNonVide(numCompte, "Le numéro de compte ne doit pas être vide.");
        this.numCompte = numCompte.trim();
    }

    public double getSolde() { return solde; }

    public void deposer(double montant) {
        Validation.verifierMontantPositif(montant);
        solde += montant;
        historique.add(new Transaction(TypeTransaction.DEPOT, montant));
    }

    public void retirer(double montant) {
        Validation.verifierMontantPositif(montant);
        Validation.verifierSoldeSuffisant(solde, montant);
        solde -= montant;
        historique.add(new Transaction(TypeTransaction.RETRAIT, montant));
    }

    public ArrayList<Transaction> getHistorique() {
        return historique;
    }

    @Override
    public String afficher() {
        return "Nom: " + nom + " | Compte: " + numCompte + " | Solde: " + solde;
    }
}
