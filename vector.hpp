using namespace std;

template <class T>
class Vector 
{
    public:
        
    typedef T &reference;
    typedef size_t size_type;
    typedef T value_type;
    typedef T *iterator;
    typedef const T *const_iterator;
    iterator duom; 
    iterator laisva; 
    iterator limitas; 
    std::allocator<T> a;

    Vector() 
    {
        create();
    }

    template <class InputIterator>
    void assign(InputIterator pradzia, InputIterator pabaiga) 
    {
        destroy();
        create(pradzia, pabaiga);
    }

    void pop_back() 
    {
        iterator nlaisva = laisva;
        a.destroy(--nlaisva);
        laisva = nlaisva;
    }

    void push_back(const value_type &sk) 
    {
        if (laisva == limitas) 
        {
            grow();
        }
        unchecked_append(sk);
    }

    void reserve(size_type n) 
    {
        if (n > capacity()) 
        {
            grow(n);
        }
    }

    void resize(size_type n) 
    {
        if (n < size()) 
        {
            laisva = duom + n;
            iterator i = limitas;
            while (i != laisva) 
            {
                a.destroy(--i);
            }
        } 
        else if (n > capacity()) 
        {
            grow(n);
            resize(n);
        } 
        else if (n > size()) 
        {
            laisva += n - size();
        }
    }
    
    const_iterator end() const noexcept 
    {
        return laisva;
    }

    const_iterator begin() const noexcept 
    {
        return duom;
    }
    
    reference back() 
    {
        return duom[size() - 1];
    }

    size_type size() const noexcept 
    {
        return laisva - duom;
    }

    size_type capacity() const 
    {
        return limitas - duom;
    }

    bool empty() const noexcept 
    {
        return size() == 0;
    }

    void create() 
    {
        duom = laisva = limitas = nullptr;
    }

    void create(size_type size, const T &skaitmuo) 
    {
        duom = a.allocate(size);
        limitas = laisva = duom + size;
        std::uninitialized_fill(duom, limitas, skaitmuo);
    }

   void unchecked_append(const T &skaitmuo) 
    {
        a.construct(laisva++, skaitmuo);
    }

    void destroy() 
    {
        if (duom) 
        {
            iterator i = laisva;
            while (i != duom) 
            {
                a.destroy(--i);
            }
            a.deallocate(duom, limitas - duom);
        }
        duom = limitas = laisva = nullptr;
    }

    void grow(size_type ncapacity = 1) 
    {
        size_type nsize = max(2 * capacity(), ncapacity);
        iterator ndata = a.allocate(nsize);
        iterator nlaisva = uninitialized_copy(duom, laisva, ndata);

        destroy();

        duom = ndata;
        laisva = nlaisva;
        limitas = ndata + nsize;
    }
};