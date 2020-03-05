#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class crypto
{
    public:
        string encode(string seed, string input)
        {
            string output;
            short ascii_value;
            char character;

            for(int i = 0, j = 0; i < input.length() - 1; i++, j++)
            {
                ascii_value = (short) input[i];
                ascii_value *= seed[j];
                output += to_string(ascii_value);

                if(j == seed.length() - 1)
                {
                    j = 0;
                }
            }
            if(output.length() > 10)
            {
                 short pos = output.length() - 10;
                 output.erase(output.length() - pos);
            }
            return output;
        }
};

class sys 
{
    public:
        string hostname;
        crypto security;

        sys(string name, string new_user, string password)
        {
            hostname = name;
            local_user = new_user;
            set_local_key(new_user, password);
        }

        bool check_user(string username){
            if(local_user == username)
            {
                return true;
            }else
            {
                return false;
            }
        }

        string get_user()
        {
            return local_user;
        }

        string get_local_key()
        {
            return local_key;
        }

        void grant_access(string user)
        {
            authorized = user;
            cout << authorized << " logged in." << endl;
        }

        bool isAuthorized()
        {
            if(authorized.compare(local_user))
            {
                return true;
            }else 
            {
                return false;
            }
        }

    private:
        string local_key;
        string local_user;
        string authorized;
        void set_local_key(string seed, string password)
        {
            local_key = security.encode(seed, password);
        }
        
};

