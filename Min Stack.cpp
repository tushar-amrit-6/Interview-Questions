Push(x) : Inserts x at the top of stack. 
If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2.
We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
  
  
Pop() : Removes an element from top of stack.  
Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). 
This is where we retrieve previous minimum from current minimum and its value in stack. 
For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.

  void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
 
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
 
        // Minimum will change as the minimum element
        // of the stack is being removed.
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
 
        else
            cout << t << "\n";
    }
 
    // Removes top element from MyStack
    void push(int x)
    {
        // Insert new number into the stack
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout <<  "Number Inserted: " << x << "\n";
            return;
        }
 
        // If new number is less than minEle
        else if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
 
        else
           s.push(x);
 
        cout <<  "Number Inserted: " << x << "\n";
    }


////MAX STACK/////

      Push(x) : Inserts x at the top of stack. 
If stack is empty, insert x into the stack and make maxEle equal to x.
If stack is not empty, compare x with maxEle. Two cases arise:
If x is less than or equal to maxEle, simply insert x.
If x is greater than maxEle, insert (2*x – maxEle) into the stack and make maxEle equal to x. 
  For example, let previous maxEle was 3. Now we want to insert 4. We update maxEle as 4 and insert 2*4 – 3 = 5 into the stack.
  
Pop() : Removes an element from top of stack. 
Remove element from top. Let the removed element be y. Two cases arise:
If y is less than or equal to maxEle, the maximum element in the stack is still maxEle.
If y is greater than maxEle, the maximum element now becomes (2*maxEle – y), so update (maxEle = 2*maxEle – y). 
  This is where we retrieve previous maximum from current maximum and its value in stack. 
  For example, let the element to be removed be 5 and maxEle be 4. We remove 5 and update maxEle as 2*4 – 5 = 3.
  
  
