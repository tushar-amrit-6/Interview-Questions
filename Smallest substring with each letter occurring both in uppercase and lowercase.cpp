Traverse the given string and store the characters whose only lowercase or uppercase form are present in the input string in a Map mp.
Initialize two arrays to keep track of the lowercase and uppercase characters obtained so far.
Now, traverse the string maintaining two pointers i and st (initialized with 0), where st will point to the start of the current substring and i will point to the current character.
If the current character is in mp, neglect all the characters obtained so far and start from the next character and adjust the arrays accordingly.
If the current character is not in mp, remove the extra characters from the beginning of the substring with the help of st pointer, such that the frequency of any character does not convert to 0 and adjust the arrays accordingly.
Now, check whether the substring {S[st], ….., S[i]} is balanced or not. If balanced and i – st + 1 is smaller than the length of balanced substring obtained so far. Update the length and also store the start and end indices of the substring, i.e. st and i respectively.
Repeat the steps till the end of the string.

#include <bits/stdc++.h>
using namespace std;

// Function to check if the current
// string is balanced or not
bool balanced(int small[], int caps[])
{
	// For every character, check if
	// there exists uppercase as well
	// as lowercase characters
	for (int i = 0; i < 26; i++) {

		if (small[i] != 0 && (caps[i] == 0))
			return 0;

		else if ((small[i] == 0) && (caps[i] != 0))
			return 0;
	}
	return 1;
}

// Function to find smallest length substring
// in the given string which is balanced
void smallestBalancedSubstring(string s)
{

	// Store frequency of
	// lowercase characters
	int small[26];

	// Stores frequency of
	// uppercase characters
	int caps[26];

	memset(small, 0, sizeof(small));
	memset(caps, 0, sizeof(caps));

	// Count frequency of characters
	for (int i = 0; i < s.length(); i++) {

		if (s[i] >= 65 && s[i] <= 90)
			caps[s[i] - 'A']++;
		else
			small[s[i] - 'a']++;
	}

	// Mark those characters which
	// are not present in both
	// lowercase and uppercase
	unordered_map<char, int> mp;
	for (int i = 0; i < 26; i++) {

		if (small[i] && !caps[i])
			mp[char(i + 'a')] = 1;

		else if (caps[i] && !small[i])
			mp[char(i + 'A')] = 1;
	}

	// Initialize the frequencies
	// back to 0
	memset(small, 0, sizeof(small));
	memset(caps, 0, sizeof(caps));

	// Marks the start and
	// end of current substring
	int i = 0, st = 0;

	// Marks the start and end
	// of required substring
	int start = -1, end = -1;

	// Stores the length of
	// smallest balanced substring
	int minm = INT_MAX;

	while (i < s.length()) {
		if (mp[s[i]]) {

			// Remove all characters
			// obtained so far
			while (st < i) {

				if (s[st] >= 65 && s[st] <= 90)
					caps[s[st] - 'A']--;
				else
					small[s[st] - 'a']--;

				st++;
			}
			i += 1;
			st = i;
		}
		else {

			if (s[i] >= 65 && s[i] <= 90)
				caps[s[i] - 'A']++;
			else
				small[s[i] - 'a']++;

			// Remove extra characters from
			// front of the current substring
			while (1) {

				if (s[st] >= 65 && s[st] <= 90
					&& caps[s[st] - 'A'] > 1) {
					caps[s[st] - 'A']--;
					st++;
				}
				else if (s[st] >= 97 && s[st] <= 122
						&& small[s[st] - 'a'] > 1) {
					small[s[st] - 'a']--;
					st++;
				}
				else
					break;
			}

			// If substring (st, i) is balanced
			if (balanced(small, caps)) {

				if (minm > (i - st + 1)) {

					minm = i - st + 1;
					start = st;
					end = i;
				}
			}
			i += 1;
		}
	}

	// No balanced substring
	if (start == -1 || end == -1)
		cout << -1 << endl;

	// Store answer string
	else {

		string ans = "";
		for (int i = start; i <= end; i++)
			ans += s[i];
		cout << ans << endl;
	}
}

// Driver Code
int main()
{

	// Given string
	string s = "azABaabba";

	smallestBalancedSubstring(s);

	return 0;
}
