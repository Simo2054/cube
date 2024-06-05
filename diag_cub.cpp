#include<iostream>
#include<fstream>
#include<stdio.h>

class cub
{
    private:
        int n;
        int ***a;
    public:
        cub(std::string file)
        {
            std::ifstream f(file);
            std::cout<<"latura cubului: "; 
            f>>n;
            std::cout<<n<<"\n";
            a=new int**[n];
            if(a==NULL)
            {
                std::cout<<"da afara din memorie!";
                return;
            }
            for(int i=0; i<n; i++)
                {
                    a[i]=new int*[n];
                    if(a[i]==NULL)
                        {
                            std::cout<<"da afara din memorie!";
                            return;
                        }
                    for(int j=0; j<n; j++)
                        {
                            a[i][j]=new int[n];
                            if(a[i][j]==NULL)
                                {
                                    std::cout<<"da afara din memorie!";
                                    return;
                                }
                        }
                }
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    for(int k=0; k<n; k++)
                        f>>a[i][j][k];
            std::cout<<"cubul va fi: \n";
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    for(int k=0; k<n; k++)
                        std::cout<<a[i][j][k]<<" ";
                    std::cout<<"\n";
                }
                std::cout<<"\n";
            }
        }

        void coordonate()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    for(int k=0; k<n; k++)
                        std::cout<<"a"<<i<<j<<k<<" ";
                    std::cout<<"\n";
                }
                std::cout<<"\n";
            }
        }

        int* diagonala(const int &diag)
        {
            int* rez;
            rez = new int[n];
            //std::cout<<"diagonala "<< diag << " este: ";
            switch(diag)
            {
                case(1):
                    for(int i=0; i<n; i++)
                    {
                        rez[i] = a[i][i][i];
                        //std::cout<<a[i][i][i]<<" ";
                    }
                    break;
                case(2):
                    for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                            for(int k=0; k<n; k++)
                                if(i==j && k==n-1-i)
                                {
                                    rez[i] = a[i][j][k];
                                    //std::cout<<a[i][j][k]<<" ";
                                }
                    break;
                case(3):
                    for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                            for(int k=0; k<n; k++)
                                if(j==k && i==n-1-j)
                                {
                                    rez[i] = a[i][j][k];
                                    //std::cout<<a[i][j][k]<<" ";
                                }
                    break;
                case(4):
                    for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                            for(int k=0; k<n; k++)
                                if(i==k && j==n-1-i)
                                {
                                    rez[i] = a[i][j][k];
                                    //std::cout<<a[i][j][k]<<" ";
                                }
                    break;
                default:
                    //std::cout<<"inexistenta!\n";
                    rez = nullptr;
            }
            return rez;
        }

        void produs(const int &diag)
        {
            int* v = diagonala(diag);
            if(v==nullptr)
                {
                    return;
                }
            std::cout<<"\n";
            long long int prod = 1.;
            for(int j = 0; j < n; j++)
                prod = prod * v[j];
            std::cout<<"produsul diagonalei este: "<<prod<<"\n";
            
        }

};

void afisare_vector(int* vector, int marime_vector)
{
    for(int i=0; i < marime_vector; i++)
        std::cout<<vector[i]<<" ";
}

/*
a000 a001 a002 
a010 a011 a012 
a020 a021 a022 

a100 a101 a102 
a110 a111 a112 
a120 a121 a122 

a200 a201 a202 
a210 a211 a212 
a220 a221 a222
*/

void numere(int &nr)
{
    std::cout<<"cat sa fie latura cubului? ";
    std::cin>>nr;
    FILE *file;
    file = fopen("input.txt", "wb");
    fprintf(file, "%d\n", nr);
    for(int i=1; i<=nr*nr*nr; i++)
        i%10==0?fprintf(file, "%d\n", i):fprintf(file,"%d ", i);
    fclose(file);
}

int main()
{
    int nr;
    int diag;
    numere(nr);
    cub c("input.txt");
    //c.coordonate(); //afiseaza structura cubului
    std::cout<<"ce diagonala se doreste? ";
    std::cin>>diag;
    std::cout<<"diagonala "<< diag << " este: ";
    if(c.diagonala(diag) != nullptr)
    {
        afisare_vector(c.diagonala(diag), nr);
    }
    else
        std::cout<<"inexistenta!\n";
    c.diagonala(diag);
    c.produs(diag);
    return 0;
}