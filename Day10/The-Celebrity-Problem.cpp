#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is the number of people at the party.
*/

#include <stack>

int findCelebrity(int n) {

    // Create a stack and push all ids in it.
    stack<int> ids;
    for(int i = 0; i < n; i++) {
        ids.push(i);
    }

    // Finding celebrity.
    while(ids.size() > 1) {
        int id1 = ids.top();
        ids.pop();
        int id2 = ids.top();
        ids.pop();
        
        if(knows(id1, id2)) {
            // Because person with id1 can not be celebrity. 
            ids.push(id2); 
        }
        else {
            // Because person with id2 can not be celebrity.
            ids.push(id1); 
        }
    }

    int celebrity = ids.top();
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celebrity = -1;
    }

    return celebrity;
}
