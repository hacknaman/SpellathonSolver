// The Game - Read the hashed file

#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<unordered_map>
#include<set>
#include<list>


using namespace std;

bool buildhashmap(unordered_map <string, list<string>  > &diction_map)
{
    ifstream hashfile;
    hashfile.open("hashbuilt.txt");

    if(hashfile.is_open())
    {
        while(!hashfile.eof())
        {
            string line1,line2;
            if(getline(hashfile,line1) && getline(hashfile,line2))
            {
                size_t pos = 0;
                string token;
                while ( (pos = line2.find("-")) != std::string::npos)
                {
                    token = line2.substr(0, pos);
                    diction_map[line1].push_front(token);
                    line2.erase(0, pos + 1);
                }
           }
        }
    }
    else
        return false;

    return true;
}

int main()
{

    unordered_map <string, list<string>  > dict_map;

    if (!buildhashmap(dict_map))
    {
        cout<< "Unable to open file";
        return 0;
    }

    cout<<"Map Built...\n";

    set<string> wordlist;

    char str_imp,str_input[7];
    int counter = 1<<6;

    cout<<"Enter 1+6 alphabets, fixed alphabet first ";
    cin >> str_imp >>str_input;

    cout<<"\n\n   Found Words:- \n\n";

    for(int i = 1 ; i<counter ; i++)
    {
        int pos = 0;
        string lookup;
        lookup.push_back(str_imp);
        int j = i;
        while(j)
        {
            if( j&1 == 1)
                lookup.push_back(str_input[pos]);
            pos++;
            j>>=1;
        }

        if(lookup.length()>=4)
        {
            sort(lookup.begin(),lookup.end());

            if(dict_map.count(lookup)>0)
            {
                list <string> word_list= dict_map[lookup];
                for(auto itr = word_list.begin() ; itr!=word_list.end(); itr++)
                {
                    if( wordlist.find(*itr) == wordlist.end() )
                        wordlist.insert(*itr);

                }
            }
        }
    }

    for(auto itr = wordlist.begin() ; itr!=wordlist.end() ; itr++)
        cout<<*itr<<endl;


    return 0;
}
