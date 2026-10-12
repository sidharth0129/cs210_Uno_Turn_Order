1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

a. concat only needs to work between two lists of the same representation because two lists of differing representations use different ways of storing data. For instance, ArrayList uses the data array (in this instance), and LinkedList uses nodes, these two things do not use the same logic, and therefore therefore my current concat implementation cannot work between them. 
2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

a. I need prev, current, and nextNode alive at once. Losing any of them will corrupt the list since prev tracks the portion that is reversed, current is the node that is changing, and nextNode is the 'rest' of the list.
3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

a. The valid range for position in addAnywhere is 0 to size_, and displays a message if a position is out of bounds. For deleteAnywhere, the valid range is 0 through size_ - 1. This also displays a message if position is out of bounds.
4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

a. I need to walk to the end of the list first, when addFront and deleteFront never needed to since I need to find the last node of the first list to connect it to the first node of the second list. add and delete Front never needed access to the rear of the list, it was as the  name suggests, from the front. If there was a tail_ pointer, we could just go to the end immediately instead of traversing the whole list. If I added it back, I would have to keep track of the tail_.
5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

a. In addAnywhere, the elements at and after position shift one index right. Shifting in the wrong direction could cause data overwrite. This would lead to me losing data I needed in order to complete the shift, new data and all.


6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
play, and explain what would visibly break in the game if that call were missing.


a. table1->reverse(); line 49 is the exact line where a Reverse card actually changes the direction of play. If that call were missing, the order of the turns would never change direction. This means that the card would have no effect and therefore break the game.


AI Disclosure: I used ChatGPT for code review and clarification of concepts that I was unfamiliar with.