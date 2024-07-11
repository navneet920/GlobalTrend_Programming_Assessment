#include<iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Codec {
public:
    
    string serialize(TreeNode* root) {
        return serializeHelper(root);
    }
    TreeNode* deserialize(const string& data) {
        queue<string> nodes = split(data, ',');
        return deserializeHelper(nodes);
    }

private:
    string serializeHelper(TreeNode* node) {
        if (node == nullptr) {
            return "#,";
        }
        return to_string(node->val) + "," + serializeHelper(node->left) + serializeHelper(node->right);
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        return node;
    }

    queue<string> split(const string& str, char delimiter) {
        queue<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push(token);
        }
        return tokens;
    }
};
int main() {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized_tree = codec.serialize(root);
    cout << "Serialized tree: " << serialized_tree <<endl;

    TreeNode* deserialized_tree = codec.deserialize(serialized_tree);
    string serialized_again = codec.serialize(deserialized_tree);
    cout << "Serialized again: " << serialized_again << endl;

    return 0;
}
