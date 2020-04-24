class GenerateurNombreAleatoire
{
protected:
    int m_dim;

public:
    GenerateurNombreAleatoire(const int dim);
    virtual ~GenerateurNombreAleatoire();
    GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other);
    GenerateurNombreAleatoire& operator=(const GenerateurNombreAleatoire &other);

    void set_dim(const int dim);
    int get_dim() const;

    virtual unsigned long long get_max() const = 0;


    virtual GenerateurNombreAleatoire* clone() = 0;

    virtual void set_seed(const unsigned long long seed) = 0;
    virtual unsigned long long get_seed() const = 0;
    virtual void reset_seed() = 0;

    virtual unsigned long long* generate() = 0;
};

