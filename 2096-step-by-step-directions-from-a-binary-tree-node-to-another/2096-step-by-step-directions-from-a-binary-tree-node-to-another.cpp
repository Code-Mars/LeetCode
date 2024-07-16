class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* start_node = nullptr;

        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();

            if (cur_node->val == startValue) {
                start_node = cur_node;
                break;
            }

            if (cur_node->left) {
                q.push(cur_node->left);
            }
            if (cur_node->right) {
                q.push(cur_node->right);
            }
        }

        unordered_map<int, TreeNode*> nodes_parents;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();

            if (cur_node->left) {
                nodes_parents[cur_node->left->val] = cur_node;
                q.push(cur_node->left);
            }
            if (cur_node->right) {
                nodes_parents[cur_node->right->val] = cur_node;
                q.push(cur_node->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(start_node);
        unordered_map<TreeNode*, pair<TreeNode*, char>> tracked_path;

        TreeNode* destination_node = nullptr;

        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();
            visited.insert(cur_node);

            if (cur_node->val == destValue) {
                destination_node = cur_node;
                break;
            }

            if (nodes_parents.find(cur_node->val) != nodes_parents.end() && visited.find(nodes_parents[cur_node->val]) == visited.end()) {
                TreeNode* parent = nodes_parents[cur_node->val];
                q.push(parent);
                tracked_path[parent] = make_pair(cur_node, 'U'); 
            }

            if (cur_node->left && visited.find(cur_node->left) == visited.end()) {
                q.push(cur_node->left);
                tracked_path[cur_node->left] = make_pair(cur_node, 'L'); 
            }

            if (cur_node->right && visited.find(cur_node->right) == visited.end()) {
                q.push(cur_node->right);
                tracked_path[cur_node->right] = make_pair(cur_node, 'R'); 
            }
        }

        stack<char> result_path;
        TreeNode* cur_node = destination_node;

        while (cur_node != start_node) {
            auto it = tracked_path.find(cur_node);
            if (it != tracked_path.end()) {
                result_path.push(it->second.second); 
                cur_node = it->second.first;
            }
        }

        string res;
        while (!result_path.empty()) {
            res += result_path.top();
            result_path.pop();
        }

        return res;
    }
};