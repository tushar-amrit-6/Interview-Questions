Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
Create a queue of char datatype.
Store each character in queue and increase its frequency in the hash array.
For every character of stream, we check front of the queue.
If the frequency of character at the front of queue is one, then that will be the first non-repeating character.
Else if frequency is more than 1, then we pop that element.
If queue became empty that means there are no non-repeating characters so we will print -1.
  
  void firstnonrepeating(char str[])
{
    queue<char> q;
    int charCount[MAX_CHAR] = { 0 };
 
    // traverse whole stream
    for (int i = 0; str[i]; i++) {
 
        // push each character in queue
        q.push(str[i]);
 
        // increment the frequency count
        charCount[str[i] - 'a']++;
 
        // check for the non pepeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }
 
        if (q.empty())
            cout << -1 << " ";
    }
    cout << endl;
}
