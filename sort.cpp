#include <iostream>
#include <vector>

void PrintVect (std::vector <int> const & v)
{
    for (auto x: v)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

void swap (std::vector <int> &v, int i, int j)
{
    int temp = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = temp;
}

void SelectionSort (std::vector <int> v)
{
    std::cout <<"Selection Sort"<<std::endl;
    PrintVect(v);
    // the algorithm and code for selection sort was taken from
    // the website http://theoryapp.com/selection-insertion-and-bubble-sort/
    if (v.size()>1)
    {
        for (auto i=0; i <v.size()-1; ++i)
        {
            bool tf = true;
            int min = i;
            for (auto j=i+1; j<v.size(); ++j)
            {
                if (v.at(j)<v.at(min))
                {
                    min = j;
                    tf = false;
                }
            }
            swap (v, i, min);
            if (!tf)
                PrintVect(v);
        }
    }

}

void InsertionSort (std::vector <int> v)
{
    std::cout <<"Insertion Sort"<<std::endl;
    PrintVect(v);
    // the algorithm and code for insertion sort was taken from
    // the website http://theoryapp.com/selection-insertion-and-bubble-sort/
    // and the reference book from wikipedia p.116
    // https://books.google.com/books?id=kse_7qbWbjsC&pg=PA116#v=onepage&q&f=false
    if (v.size()>1)
    {
        for (auto i=1; i <v.size(); ++i)
        {
            
            int j;
            for (j=i; j>0 && v.at(j-1)>v.at(j); --j)
            {
                swap (v, j-1, j);
                PrintVect(v);
            }
        }
    }
}

void BubbleSort (std::vector <int> v)
{
    std::cout <<"Bubble Sort"<<std::endl;
    PrintVect(v);
    if (v.size()>1)
    {
        // the algorithm and code for bubble sort was taken from
        // the website http://theoryapp.com/selection-insertion-and-bubble-sort/
        for (int i=v.size()-1; i>=0; --i)
        {
            bool tf = true;
            for (auto j=0; j<=i-1; ++j)
            {
                if (j==v.size()-1)
                {
                    break;
                }
                if (v.at(j) > v.at(j+1))
                {
                    swap (v, j, j+1);
                    PrintVect(v);
                }     
            }
        }
    }
}

int main()
{
    int x;
    
    std::vector<int> v;
    while (std::cin>>x)
    {
        v.push_back(x);
    }
    SelectionSort(v);
    InsertionSort (v);
    
    BubbleSort(v);


    return 0;
}
