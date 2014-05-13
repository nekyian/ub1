template <class T>
class node
{
    public:
        T data;
        node *right,*left;
        node(){right = NULL; left = NULL;}
        node(const T& d){right = NULL; left = NULL; data = d;}
};
