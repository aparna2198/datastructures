/*
https://www.youtube.com/watch?v=shs0KM3wKv8
hash function  very important
have hash fucntion as the possibke solution at the top of your mind for problem solving
hash table is a key value look up
situaution where u eed to associate somebodys name with a set of information about them hash table would be perfect solution
for eg hashtable.et("mary") boom u get data associative mary
mary is the key 
the key as well as the value can be any type of data structures
a string or it could be circlr or square as long as u have a hash function

so here u passed mary which is a string
how do we jump from string to index  in that array thats what a hash fucntion does
so hash function takes in a string 
converts it to somesort of interger
and then remaps that interger into an index into that array
and thats where we can find the person we are looking for
 
the hash code is not the index code in this array 
we map actually from the key to the hash code and than over to the index 
array that stores data  form the hash table might be much much smaller than all the available potential hash codes
so we dont wanna have 3 billion array just because we have 3 billion hash codes
so we actually remap into some thing smaller 

note--
two different strings  can actually have the same hash codes
because there are infinite number of strings but finite number of hash codes
 
 infinte strings ---> finite hash codes ---> even more finite index
 so two members can have same hash codes (aryan n sweety   suppose ) 
 also we mapping hash codes into even smaller index 
 two things with different hash codes  could actually wind up maps same index
 so COLLISION CAN OCCUR
many methods to resolve collision 
one of them is chaining which says hey when there is a collision store them in  a link list
rather than it being array of people it will be a array of link list of people
 when suppose u want to get the value of alex u need to look through all  the values in that link list and pull out the value for alex
now this link list contains not just the actual person objects but the actual original keys as well
reason beign if u store only person object u will see all these people 
who mapped to this index  but u wouldnt know which one they are 
so u need to store keys along with objects 
*/
