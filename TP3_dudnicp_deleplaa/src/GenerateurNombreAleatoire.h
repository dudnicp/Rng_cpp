class GenerateurNombreAleatoire
{
private:
    int m_dim;
public:
    GenerateurNombreAleatoire(const int dim);
    virtual ~GenerateurNombreAleatoire();
    GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other);
    void operator=(const GenerateurNombreAleatoire &other);

    void set_dim(const int dim);
    int get_dim() const;


    void clone(const GenerateurNombreAleatoire &other);

    virtual void set_seed(const int seed) = 0;
    virtual int get_seed() const = 0;
    virtual void reset_seed() = 0;

    virtual double* generate() = 0;
};

