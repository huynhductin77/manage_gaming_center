#ifndef STR_H
#define STR_H
string delSpaceChar(string& result)
{
    for(int i = result.length() - 1; i >= 0; i--) //del space character at the tail of string 
    {
        if(result.at(i) ==  ' ')
        {
            result.pop_back();
        }
        else
            break;
    }
    for(int i = 0; i < result.length(); i++) //del space character at the head of string 
    {
        if(result.at(i) ==  ' ')
        {
            i--;
            result = result.substr(1, result.length() - 1);
        }
        else
            break;
    }
    return result;
}
string formatStr(string& result)
{
    delSpaceChar(result);
    if(!isupper(result.at(0)))
    {
        result.at(0) = toupper(result.at(0));
    } // first character
    for(int i = 0; i < result.length() - 1; i++)
    {
        if(result.at(i) == ' ' && islower(result.at(i+1)))
            result.at(i+1) = toupper(result.at(i+1));
    } // " *" --> upper *
    for(int i = 0; i < result.length() - 1; i++)
    {
        if(isalpha(result.at(i)) && isupper(result.at(i+1)))
            result.at(i+1) = tolower(result.at(i+1));
    } // "**" --> lower * 2nd
    return result;
}
#endif