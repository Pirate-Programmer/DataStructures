<h1>LinkedList</h1>

<p>Implements a basic LinkedList</p>
<pre><code>
typedef struct node
{
    int element;
    struct node* next;
}node;
</code></pre>

<p>Includes Some Basic Functions for the above LinkedList</p>
<ul>
     <li>add(prepend/postpend/add in a sorted manner)</li>
     <li>delete node</li>
     <li>sort functions</li>
     <li>reverse functions</li>
     <li>search functions</li>
<ul>

<p>Insertion takes O(1) </p>
<p>Deletion takes O(1) / O(k) k dist away from head </p>
<p>Search takes O(n) </p>
<p>sort could take O(nlogn)</p>
<p>Reverse takes O(n) </p>
