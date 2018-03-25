class P1
{
public:
    P1 () { p = new char [10]; }
    ~P1 () { delete [] p; }
private:
    char * p;
};
class P2 : public P1
{
public:
    P2 () { q = new char [20]; }
    ~P2 () { delete [] q; }
private:
    char * q;
};

int main(int argc, char* argv[])
{
    P1 * pp = new P2;
    ...
    delete pp;
    return 0;
}
