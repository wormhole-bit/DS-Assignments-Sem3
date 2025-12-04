#include <bits/stdc++.h>
using namespace std;
bool hasDuplicates(const vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
        if (s.find(x) != s.end()) return true;
        s.insert(x);
    }
    return false;
}
vector<int> commonElements(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> s(A.begin(), A.end());
    unordered_set<int> common;
    for (int x : B) {
        if (s.find(x) != s.end()) common.insert(x);
    }
    vector<int> res(common.begin(), common.end());
    sort(res.begin(), res.end());
    return res;
}
unordered_map<int,int> frequencyMap(const vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    return freq;
}
pair<bool,int> firstNonRepeating(const vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    for (int x : nums) {
        if (freq[x] == 1) return {true, x};
    }
    return {false, 0};
}
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(nullptr) {}
};
bool hasLoop_hash(ListNode* head) {
    unordered_set<ListNode*> seen;
    ListNode* cur = head;
    while (cur) {
        if (seen.find(cur) != seen.end()) return true;
        seen.insert(cur);
        cur = cur->next;
    }
    return false;
}
bool hasLoop_floyd(ListNode* head) {
    if (!head) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
ListNode* createListWithLoop(const vector<int>& vals, int loopIndex) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    vector<ListNode*> nodes;
    nodes.push_back(head);
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
        nodes.push_back(cur);
    }
    if (loopIndex >= 0 && loopIndex < (int)nodes.size()) {
        cur->next = nodes[loopIndex];
    }
    return head;
}
void freeList(ListNode* head, int maxNodes = 100000) {
    unordered_set<ListNode*> seen;
    ListNode* cur = head;
    while (cur && seen.find(cur) == seen.end()) {
        seen.insert(cur);
        ListNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};
bool treeHasDuplicates(TreeNode* root) {
    unordered_set<int> seen;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        if (!node) continue;
        if (seen.find(node->val) != seen.end()) return true;
        seen.insert(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    return false;
}
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "1) Check duplicates in array\n";
    vector<int> nums1 = {1,2,3,1};
    cout << "Input: [1,2,3,1]\n";
    cout << (hasDuplicates(nums1) ? "Output: true\n" : "Output: false\n");
    cout << "\n";
    cout << "2) Common elements of two arrays\n";
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};
    auto common = commonElements(A,B);
    cout << "A = [1,2,3,4], B = [3,4,5,6]\nOutput: ";
    if (common.empty()) cout << "none\n";
    else {
        for (size_t i=0;i<common.size();++i) {
            if (i) cout << ", ";
            cout << common[i];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "3) Frequency count\n";
    vector<int> nums2 = {2,3,2,4,3,2};
    cout << "Input: [2,3,2,4,3,2]\n";
    auto freq = frequencyMap(nums2);
    vector<int> keys;
    for (auto &p : freq) keys.push_back(p.first);
    sort(keys.begin(), keys.end());
    for (int k : keys) {
        cout << k << " -> " << freq[k] << " times\n";
    }
    cout << "\n";
    cout << "4) First non-repeating element\n";
    vector<int> nums3 = {4,5,1,2,0,4};
    cout << "Input: [4,5,1,2,0,4]\n";
    auto res = firstNonRepeating(nums3);
    if (res.first) cout << "Output: " << res.second << "\n";
    else cout << "Output: No non-repeating element\n";
    cout << "\n";
   cout << "5) Linked list loop detection\n";
    vector<int> listvals = {1,2,3,4,2}; // we will make loop to index 1 (0-based)
    ListNode* headLoop = createListWithLoop({1,2,3,4}, 1); // loop at node with value 2
    cout << "List: 1 -> 2 -> 3 -> 4 -> back to node 2\n";
    cout << "Detection using hash set: " << (hasLoop_hash(headLoop) ? "true\n" : "false\n");
    cout << "Detection using Floyd's algorithm: " << (hasLoop_floyd(headLoop) ? "true\n" : "false\n");
    freeList(headLoop);
    cout << "\n";
    cout << "6) Binary tree duplicate detection (not BST)\n";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2); // duplicate value
    cout << "Tree contains duplicate? " << (treeHasDuplicates(root) ? "Duplicates Found\n" : "No Duplicates\n");
    freeTree(root);

    return 0;
}
