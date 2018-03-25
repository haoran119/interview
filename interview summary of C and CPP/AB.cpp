class A
{
public:
    A () : data (0) { SetData (); printf ("data=%d", data); }
    virtual void SetData () { data = 1; }
protected:
    int data;
};

class B : public A
{
public:
    B () {}
    virtual void SetData () { data = 2; }
};

int main(int argc, char* argv[])
{
    B b;
    return 0;
}
