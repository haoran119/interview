class TestSize1
{
public:
    TestSize1 () : a (0) {}
    virtual void F () = 0;
private:
    int a;
};
class TestSize2 : public TestSize1
{
public:
    TestSize2 () : b (1) {}
    virtual void F () { b = 3; }
private:
    int b;
};
int main(int argc, char* argv[])
{
    printf ("size of TestSize2 = %d", sizeof (TestSize2));
    return 0;
}
