#include <iostream>
#include <memory>

using namespace std;

struct Content
{
    private:
        string info;

    public:
        Content(string info) 
        {
            this->info = info;
        }

        void getInfo()
        {
            cout << info << endl;
        }
};


int main()
{
    /* 
    01 - STACK
    Content content("placidao bunitao");
    content.getInfo();
    */

    /* 
    02 - MEMORIA BRUTA
    Content *content = new Content("placidao gostosaum");
    content->getInfo();
    delete content;
    */

    shared_ptr<Content> content = make_shared<Content>("plazidao aoao");
    content->getInfo();

    return 0;
}