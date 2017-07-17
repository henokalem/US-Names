#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int nameToYear(string fileName, string name)
{
	ifstream myfile2(fileName);
	string line;
	if(myfile2.is_open())
	{
		while(getline(myfile2, line))
		{
			stringstream ss(line);
			string token;
			getline(ss, token, ',');
			if(token == name)
			{
				getline(ss, token, ',');
				getline(ss, token, ',');
				int output = stoi(token);
				return output;
			}
		}
	}
	return 0;
}

int yearCount(string fileName)
{       
        ifstream myfile2(fileName);
        string line;
	int output = 0;
        if(myfile2.is_open())
        {       
                while(getline(myfile2, line))
                {       
                        stringstream ss(line);
                        string token;
                        getline(ss, token, ',');
                        getline(ss, token, ',');
                        getline(ss, token, ',');
                        output += stoi(token);
                }
        }
        return output;
}

int nameCount(string fileName, string name)
{
        ifstream myfile(fileName);
        string line;
        int totalCount = 0;
        if(myfile.is_open())
        {
                while(getline(myfile, line))
                {
                        totalCount+=nameToYear(line, name);
                }
                myfile.close();
        }
	return totalCount;	
}

int genderToYear(string fileName, string gender)
{       
        ifstream myfile2(fileName);
        string line;
	int output = 0;
        if(myfile2.is_open())
        {       
                while(getline(myfile2, line))
                {       
                        stringstream ss(line);
                        string token;
                        getline(ss, token, ',');
                        getline(ss, token, ',');
			if(token[0] == gender[0])
			{
                                getline(ss, token, ',');
                                output += stoi(token);
                        }
                }
        }
        return output;
}

int genderCount(string fileName, string gender)
{       
        ifstream myfile(fileName);
        string line;
        int totalCount = 0;
        if(myfile.is_open())
        {       
                while(getline(myfile, line))
                {       
                        totalCount+=genderToYear(line, gender);
                }
                myfile.close();
        }
        return totalCount;
}

int nameToYearToGender(string fileName, string name, string year, string gender)
{
        ifstream myfile2(fileName);
        string line; 
        int output = 0;
        if(myfile2.is_open())
        {       
                while(getline(myfile2, line))
                {       
                        stringstream ss(line);
                        string token;
                        getline(ss, token, ',');
			if(token == name)
			{
                        	getline(ss, token, ',');
                        	if(token[0] == gender[0])
                        	{       
                                	getline(ss, token, ',');
                                	output += stoi(token);
                        	}
			}
                }
        }
        return output;
}

int nameToGender(string fileName, string name, string year, string gender)
{
        ifstream myfile(fileName);
        string line;
        int totalCount = 0;
        if(myfile.is_open())
        {
                while(getline(myfile, line))
                {
                        totalCount+=nameToYearToGender(line, name, year, gender);
                }
                myfile.close();
        }
        return totalCount;
}

int main(int argc, char* argv[])
{
	if(argc != 4 && argc != 5)
	{
		cout << "Usage: ./getName [First Name] [Year] [Gender]" << endl;
		cout << "Type '/Null' for unecessary parameters." << endl;
		return 0;
	}
	
	if(argc == 4)
	{

        	string name, year, gender;
        	name = argv[1];
        	year = argv[2];
        	gender = argv[3];
		string fileName = "namesData/yob" + year + ".txt";

		if(name != "Null" && year == "Null" && gender == "Null")
		{
			cout << nameCount("inputFile.txt", name) << " new Social Security applicats by the name " << name << " between 1880-2014." << endl;
		}
		else if(name != "Null" && year != "Null" && gender == "Null")
		{
			cout << nameToYear(fileName, name) << " new Social Security applicats by the name " << name << " in the year " << year << endl;
		}
		else if(name != "Null" && year == "Null" && gender != "Null")
		{
			cout << nameToGender("inputFile.txt", name, year, gender) << " new " << gender << " Social Security applicants by the name " << name << " between 1880-2014." << endl;
		}
		else if(name != "Null" && year != "Null" && gender != "Null")
		{
			cout << nameToYearToGender(fileName, name, year, gender) << " new " << gender << " Social Security applicants by the name " << name << " in the year " << year << endl;
		}
		else if (name == "Null" && year != "Null" && gender == "Null")
		{
			cout << yearCount(fileName) << " new Social Security applicants in the year " << year << endl;
		}
		else if (name == "Null" && year != "Null" && gender != "Null")
		{
			cout << genderToYear(fileName, gender) << " new " << gender << " Social Security applicants in the year " << year << endl;
		}
		else if(name == "Null" && year == "Null" && gender != "Null")
		{
			cout << genderCount("inputFile.txt", gender) << " new " << gender << " Social Security applicants in the year " << year << endl;
		}
	}
	if(argc == 5)
	{
		string name, yearStart, yearEnd,gender;
		name = argv[1];
		yearStart = argv[2];
		yearEnd = argv[3];
		gender = argv[4];
		int start = stoi(yearStart);
		int end = stoi(yearEnd);
		int total = 0;
		while(start <= end)
		{
			yearStart = to_string(start);
			string fileName = "namesData/yob"+yearStart+".txt";
			if(gender == "Null")
				total += nameToYear(fileName, name);
			else if(name == "Null")
				total += genderToYear(fileName, gender);
			else
				total += nameToYearToGender(fileName, name, yearStart, gender);

			++start;
		}
		cout << total << " with features " << name << " and " << gender << " applied for Social Security Cards." << endl;
		
	}
	
	return 0;
}
