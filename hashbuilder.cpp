// make a hashmap of the dictionary (dict.txt) and store it in a file (hashbuilt.txt)
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<unordered_map>
#include<list>

using namespace std;

int main()
{
    string line;
    ifstream file;
    file.open("dict.txt");

    unordered_map <string, list<string>  > dict_map;

    if(file.is_open())
    {
        cout<<"Initializing dictionary processing... ";

        while(getline(file,line))
        {
            if( line.length() >=4 && line.length()<=7 )
            {
                string temp_line = line;
                sort(temp_line.begin(),temp_line.end());
                dict_map[temp_line].push_front(line);
            }
        }

        cout<<"\nDictionary processing complete... \nNow Saving it to file hashbuilt.txt...";

        ofstream hashfile;
        hashfile.open("hashbuilt.txt");

        for(auto itr = dict_map.begin(); itr!=dict_map.end(); itr++)
        {
            hashfile << itr->first.c_str() <<"\n";

            list <string> temp = itr->second;
            for(auto str = temp.begin() ; str!=temp.end(); str++)
                hashfile<< str->c_str() << "-";

            hashfile << "\n";
        }

        cout<<"\nSave complete..."<<endl;

        hashfile.close();
        file.close();
    }
    else
        cout<<"Unable to open file";

    return 0;
}
