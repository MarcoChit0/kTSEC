#include <iostream>
#include <vector> 
#include <utility> 

class arc { 
    public  : 
        void PrintArc(); 
        void CreateArc(int s, int d);
        void ChangeCover( int c); 
        void AddTrail(); 
        int InformNumberOfTrails();

    private : 
        int coveredBy; 
            // number of trails that cover that arc
        int numberOfTrails; 
            // first    =   source 
            // second   =   destiny 
        std::pair <int, int> edge; 
}; 


class trail {

    public : 
        void    PrintTrail();
        void    CreateTrail(std::vector <arc> new_trail); 
        void    ChangeHead( int new_head);
        void    ChangeTail( int new_tail);
        int     return_size(); 
        int     Return_numberOfTrails(); 

    private : 
        std::vector < arc > t; 
        int numberOfTrails;
        int head; 
        int tail; 
        int size; 
};

class set{ 
    public: 
        void CreateSet(std::vector <trail> new_setOfTrails); 
        void AddTrail(trail new_trail);
        void QuickSort();  
        void PrintSet(); 
    private: 
        std::vector <trail> trails;
        std::vector <int> size; 
        std::vector <int> numberOfTrails; 
};


