#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Page
{
    int maxSize;
    
    public:
    int size;
    vi records;
    Page(int maxSize)
    {
        size=0;
        this->maxSize=maxSize;
    }
    bool insert(int);
    int remove();
};
bool Page::insert(int record)
{
    if(size>=maxSize)
    {
        return false;
    }
    size++;
    records.push_back(record);
    return true;
}
int Page::remove()
{
    int returnData=records[0];
    records.erase(records.begin());
    size--;
    return returnData;
}
void print(vector<Page> pages)
{
    cout<<endl<<endl;
    for(int i=0 ; i<pages.size() ; i++)
    {
        for(int j=0 ; j<pages[i].size ; j++)
        {
            cout<<pages[i].records[j]<<" ";
        }
        cout<<endl<<endl;
    }
}
vector<Page> externalSort(vector<Page> file, int bufferSize, int recordsPerPage, int bWay)
{
    vector<Page> returnValue;
    int fileSize=file.size();
    for(int i=0 ; i<fileSize ; i+=bufferSize)
    {
        for(int j=0 ; j<bWay ; j++)
        {
            if(j+i<fileSize)
            {
                sort(file[i+j].records.begin(), file[i+j].records.end());
            }
        }
        Page run(bufferSize*recordsPerPage);
        // auto temp=file.begin()+i;
        bool status=true;
        while(status)
        {
            int min=i;
            bool exit=false;
            for(int j=0 ; j<bWay ; j++)
            {

                if(j+i<fileSize)
                {
                    if(file[i+j].size==0)
                    {
                        exit=true;
                        continue;
                    }
                    else
                        exit=false;
                    if(file[i+j].records[0]<file[min].records[0])
                        min=i+j;
                }
            }
            if(exit)
                status=false;
            else
            {
                int t=file[min].remove();
                run.insert(t);
                // cout<<t<<" ";
            }
        }
        cout<<endl;
        returnValue.push_back(run);
    }
    print(returnValue);
    return returnValue;
}
int main()
{
    int bufferSize;
    int recordsPerPage;
    int nofRecords;
    cin>>bufferSize>>recordsPerPage>>nofRecords;
    int nofPages=(nofRecords+recordsPerPage-1)/recordsPerPage;
    vector<Page> pages;
    Page temp(recordsPerPage);
    pages.push_back(temp);
    int pageTop=0;
    int value;
    for(int i=0 ; i<nofRecords ; i++)
    {
        cin>>value;
        if(pages[pageTop].insert(value)==false)
        {
            // cout<<"New page\n";
            Page newPage(recordsPerPage);
            newPage.insert(value);
            pages.push_back(newPage);
            pageTop++;
        }
        // else
            // cout<<"inserted\n";
    }
    
    vector<Page> tempSorted = externalSort(pages, bufferSize, recordsPerPage, 2);
    cout<<"blabla";
    cout<<endl<<endl;
    for(int i=0 ; i<tempSorted.size() ; i++)
    {
        for(int j=0 ; j<tempSorted[i].size ; j++)
        {
            cout<<tempSorted[i].records[j]<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}