/* ------------------------------------------------command.cpp----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is an object class to parse the command lines take from the text files into objects by commas 
and has multiple functions to help functions in store to parse the commands further based off of 
the full knowledge that the store class has
--------------------------------------------------------------------------------------*/
#include "command.h"

/* ------------------------------------(Commands)--------------------------------------
Description: defaults everything to empty
-------------------------------------------------------------------------------------- */
Commands::Commands() 
{
	
}

/*Commands::Commands(const Commands &rhs) 
{
	for (int i = 0; i < this->parsedCommand.size(); i++)
	{
		parsedCommand.at(i) = rhs.parsedCommand.at(i);
	}
		//return true;
	//return *this;
}*/

/* ------------------------------------(~Commands)--------------------------------------
Description: does nothing no dynamic memory 
-------------------------------------------------------------------------------------- */
Commands::~Commands()
{
}

/* ------------------------------------(Commands)--------------------------------------
Description: takes in the command string and parses it by commas and put into a vector
having the commandType char in the 0 index
-------------------------------------------------------------------------------------- */
Commands::Commands(string command)
{
	// check if the first spot is not an int
	if (!isdigit(command.at(0)))
	{
		// parse off the Letter indicating the command
		char commandType = command.at(0);

		// bool to mark if command is vaild
		bool valid = false;
		// check if commandType is one of the vaild ones in the vectors holding 
		// movie creation command types
		for (int i = 0; i < getCommandTypes().size(); i++)
		{
			// if command is found in vaild command mark it as vaild
			if (getCommandTypes().at(i) == commandType)
			{
				valid = true;
				string letter = "";
				letter += commandType;
				parsedCommand.push_back(letter);
				break;
			}
		}
		// if not vaild command print error
		if (!valid)
		{
			printErrorMessage(error1);
			cerr << command << endl;
			validCommand = false;
		}
		else if (valid)
		{
            if(commandType != showInventory){
                if(commandType == createComedy || commandType == createDrama || commandType == createClassic){
                    // cut off the commandType from command string
                    command = command.substr(2, command.length());

                    // finish parsing the command string and storing in vector
                    while (!command.empty()){
                        // find next comma index
                        int end = command.find(",");
                        // check if a comma was found
                        if (end != -1){
                            // parse command string to the next comma and store in vector
                            parsedCommand.push_back(command.substr(1, end - 1));
                            // fix command - erase piece just parsed
                            command = command.substr(end + 1, command.length());

                            //removes any potential carriage returns
                            /*if(!command.empty() && command[command.length() - 1] == '\r')
                            {
                                cout << "Test print" << endl;
                                command.erase(command.length() - 1);
                            }*/
                        }
                        // put whole command string into the vector
                        else{
                            command = command.substr(1, command.length());
                            parsedCommand.push_back(command);

                            // empty the command ok
                            command.clear();
                        }
                    }
                }else if(commandType == showCustomerHistory || commandType == checkoutItem
                    || commandType == givebackItem){
                    // cut off the commandType from command string
                    command = command.substr(1, command.length());

                    // finish parsing the command string and storing in vector
                    while (!command.empty()){
                        // find next comma index
                        int end = command.find(",");
                        // check if a comma was found
                        if (end != -1){
                            // parse command string to the next comma and store in vector
                            parsedCommand.push_back(command.substr(1, end - 1));
                            // fix command - erase piece just parsed
                            command = command.substr(end + 1, command.length());

                            //removes any potential carriage returns
                            /*if(!command.empty() && command[command.length() - 1] == '\r')
                            {
                                cout << "Test print" << endl;
                                command.erase(command.length() - 1);
                            }*/
                        }
                            // put whole command string into the vector
                        else{
                            command = command.substr(1, command.length());
                            parsedCommand.push_back(command);

                            // empty the command ok
                            command.clear();
                        }
                    }
                }
            }
		}
	}
	// check is first character is an index
	else if (isdigit(command.at(0)))
	{
		// check if the first 4 index spots are ints
		if (isdigit(command.at(0)) && isdigit(command.at(1)) && isdigit(command.at(2)) && isdigit(command.at(3)))
		{
			// create a new commandType K for customer accounts
			string createCustomer = "K";
			// put the newly created commandType into index 0 of the vector
			parsedCommand.push_back(createCustomer);
			// put the rest of the command into the vector
			parsedCommand.push_back(command);
		}
		else
		{
			printErrorMessage(error1);
			cerr << command << endl;
			validCommand = false;
		}
	}
}

/* ------------------------------------(getCommandTypes)--------------------------------------
Description: return the vector that holds all the valid command types to be checked against
allows users to extend and add new valid commands easily
-------------------------------------------------------------------------------------- */
vector<char> Commands::getCommandTypes()
{
	return this->commandTypes;
}//close getCommand

/* ------------------------------------(printErrorMessage)--------------------------------------
Description: pass in the error message wanted
 enables lots of error printing without changing the function just adding error messages
-------------------------------------------------------------------------------------- */ 
void Commands::printErrorMessage(string errorType)
{
	// print out the error message that was passed in
	cerr << errorType;
}

/* ------------------------------------(getVector)--------------------------------------
Description: getter for the vector storing the parsed command
-------------------------------------------------------------------------------------- */ 
vector<string> Commands::getVector()
{
	return parsedCommand;
}

/* ------------------------------------(getVector)--------------------------------------
Description: return the string at the given index in the vector
-------------------------------------------------------------------------------------- */ 
string Commands::getVector(int index)
{
	return parsedCommand[index];
}

/* ------------------------------------(getVector)--------------------------------------
Description: return true if the commands object is valid
-------------------------------------------------------------------------------------- */ 
bool Commands::isValid() 
{
	return validCommand;
}

/* ------------------------------------(convertToStringstream)--------------------------------------
Description: convert the passed in string to a stringstream to make for easier
string parseing by using >>
-------------------------------------------------------------------------------------- */ 
stringstream Commands::convertToStringstream(string stringToSplit)
{
	// string stream set equal to the passed string
	stringstream stringStream(stringToSplit);
	// return the stringstream 
	return stringStream;
}

/* ------------------------------------(spaceParser)--------------------------------------
Description: parse the passed in string by spaces
-------------------------------------------------------------------------------------- */ 
vector<string> Commands::spaceParser(string stringToSplit)
{
	// string stream set equal to the passed string
	stringstream stringStream(stringToSplit);
	// create a vector to return
	vector<string> parsed;
	// whole the stringstream isn't empty
	while (stringStream.rdbuf()->in_avail() != 0)
	{
		// string to hold the individual strings from stringStream
		string temp = "";
		// put the first string into temp
		stringStream >> temp;
		// put temp into the vector
		parsed.push_back(temp);
	}
	// return the vector 
	return parsed;
}

/* ------------------------------------(spaceParser)--------------------------------------
Description:  use the passed in index to get the string in the parsedCommand vector
-------------------------------------------------------------------------------------- */ 
vector<string> Commands::spaceParser(int index)
{
	// string stream set equal to the passed string
	stringstream stringStream(parsedCommand[index]);
	// create a vector to return
	vector<string> parsed;
	// while the stringstream isn't empty
	while (stringStream.rdbuf()->in_avail() != 0)
	{
		// string to hold the individual strings from stringStream
		string temp = "";
		// put the first string into temp
		stringStream >> temp;
		// put temp into the vector
		parsed.push_back(temp);
	}
	// return the vector 
	return parsed;
}

/* ------------------------------------(operator==)--------------------------------------
Description:  compare all values in the parsed command, return true if equal
-------------------------------------------------------------------------------------- */ 
bool Commands::operator==(const Commands& rhs) const
{
	// compare the vector sizes first
	if (this->parsedCommand.size() != rhs.parsedCommand.size())
	{
		return false;
	}
	// go through the vectors
	else
	{
		for (int i = 0; i < this->parsedCommand.size(); i++)
		{
			// if any value is not equal
			if (this->parsedCommand.at(i) != rhs.parsedCommand.at(i))
			{
				return false;
			}
		}
		return true;
	}
}

/* ------------------------------------(isEqual)--------------------------------------
Description:  compare the values in the parsed command at index 1,  
return true if equal. Exclusively used in hashWaitlist. 
-------------------------------------------------------------------------------------- */ 
bool Commands::isEqual(const Commands& rhs)
{
	// compare the vector sizes and check if null first
	
	if (this != NULL && &rhs != NULL); 
	{
		//return false;
	

	if (this->parsedCommand.size() != rhs.parsedCommand.size())
	{
		return false;
	}
	// go through the vectors
	else
	{
		string toParse = parsedCommand.at(1);
		vector<string> parsed = spaceParser(toParse);
		vector<string> rhsParsed = spaceParser(rhs.parsedCommand.at(1));

		for (int i = 1; i < parsed.size(); i++)
		{
			// if any value is not equal
			if (parsed[i] != rhsParsed[i])
			{
				return false;
			}
		}
		return true;
	}
	}
}

/* ------------------------------------(operator!=)--------------------------------------
Description:  compare all values in the parsed command, return true if not equal
-------------------------------------------------------------------------------------- */ 
bool Commands::operator!=(const Commands& rhs) const
{
	if (!(*this == rhs))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------(operator=)--------------------------------------
Description: assignment operator
-------------------------------------------------------------------------------------- */ 
void Commands::makeCopy(const Commands& rhs) 
{
	for (int i = 0; i < rhs.parsedCommand.size(); i++)
	{
		parsedCommand.push_back(rhs.parsedCommand.at(i));
	}
		//return true;
	//return *this;
}	
