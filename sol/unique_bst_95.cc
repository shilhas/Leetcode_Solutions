/**
* See LC 95 for PS
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

    vector<TreeNode*>node_factory(int start, int end) {
        
        if (start > end) return {nullptr};
        if (start == end) return {new TreeNode(start)};
        
        vector<TreeNode*>res;
        for (int i = start; i <= end; i++) {
            // int left_node_count = n-i;
            vector<TreeNode*>left_sub_trees = node_factory(start, i-1);
            for (auto left_sub_tree: left_sub_trees){
                vector<TreeNode*>right_sub_trees = node_factory(i+1, end);
                for (auto right_sub_tree: right_sub_trees) {
                    TreeNode* root = new TreeNode(i, left_sub_tree, right_sub_tree);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return node_factory(1,n);
    }
};


// Helper struct to store detailed information about each node for printing.
// This includes its position in the conceptual 2D grid and its display properties.
struct PrintNodeInfo {
    TreeNode* node;    // Pointer to the actual TreeNode
    int x_inorder;     // A unique horizontal index assigned during in-order traversal.
                       // This helps maintain relative horizontal ordering of nodes.
    int y_depth;       // The depth (level) of the node in the tree (0 for root, 1 for children, etc.).
    int width;         // The character width of the node's value string (e.g., "100" has width 3).
};

// Function to print the binary tree in a visual "tree form" to the console.
// It takes the root of the tree as input.
void printTree(TreeNode* root) {
    // Handle the case of an empty tree.
    if (!root) {
        std::cout << "Empty tree." << std::endl;
        return;
    }

    // --- Step 1: Collect Node Information and Calculate In-Order X-coordinates ---
    // This step uses an in-order traversal to assign a unique, ordered horizontal
    // (x) coordinate to each node. This relative x-coordinate is crucial for spacing
    // nodes correctly in the console output. We also track the maximum depth of the tree.

    int current_inorder_x_counter = 0; // A counter to assign unique x_inorder values (starts from 0)
    int max_tree_depth = 0;            // Keeps track of the deepest level reached in the tree

    // A map to store PrintNodeInfo structs, keyed by their in-order x_coordinate.
    // This allows for quick lookup of node details based on their horizontal position.
    std::map<int, PrintNodeInfo> node_inorder_map;

    // A vector of vectors to store PrintNodeInfo structs, grouped by their depth.
    // This facilitates printing the tree level by level.
    std::vector<std::vector<PrintNodeInfo>> nodes_by_depth_storage;

    // Recursive helper function for performing the in-order traversal.
    // It populates `node_inorder_map` and `nodes_by_depth_storage`.
    // Parameters:
    //   node: The current node being visited.
    //   depth: The current depth of the node (starts at 0 for the root).
    std::function<void(TreeNode*, int)> populate_node_details_recursive =
        [&](TreeNode* node, int depth) {
        if (!node) {
            return; // Base case: If the node is null, stop.
        }

        // Ensure `nodes_by_depth_storage` has enough capacity for the current depth.
        if (depth >= nodes_by_depth_storage.size()) {
            nodes_by_depth_storage.resize(depth + 1);
        }

        // Recursively visit the left subtree.
        populate_node_details_recursive(node->left, depth + 1);

        // Process the current node (this is the "visit" part of in-order traversal).
        // Assign its in-order x_coordinate, depth, and calculate its display width.
        PrintNodeInfo info;
        info.node = node;
        info.y_depth = depth;
        info.x_inorder = current_inorder_x_counter; // Assign unique x_inorder
        info.width = std::to_string(node->val).length(); // Calculate string length of value

        node_inorder_map[current_inorder_x_counter] = info;    // Store in map by x_inorder
        nodes_by_depth_storage[depth].push_back(info);         // Store in vector by depth

        current_inorder_x_counter++; // Increment counter for the next node in in-order sequence
        max_tree_depth = std::max(max_tree_depth, depth); // Update the maximum depth found so far

        // Recursively visit the right subtree.
        populate_node_details_recursive(node->right, depth + 1);
    };

    // Start the recursive population process from the root at depth 0.
    populate_node_details_recursive(root, 0);

    // --- Step 2: Determine Display Dimensions and Initialize Grid ---

    // Find the minimum and maximum in-order x_coordinates across all nodes.
    // These define the horizontal span of the tree in our virtual grid.
    int min_overall_x_inorder = node_inorder_map.begin()->first;
    int max_overall_x_inorder = node_inorder_map.rbegin()->first;

    // Estimate the maximum character length of any node's value string.
    // This helps determine appropriate spacing to prevent overlapping text.
    size_t max_val_char_len = 1; // Minimum width for single digit
    for (const auto& pair : node_inorder_map) {
        max_val_char_len = std::max(max_val_char_len, std::to_string(pair.second.node->val).length());
    }

    // Define a `SLOT_WIDTH` for each conceptual "column" in our console output.
    // This heuristic includes space for the node value plus some padding.
    // E.g., if max_val_char_len is 3 ("100"), SLOT_WIDTH could be 3 + 3 = 6 (" 100  ").
    const int SLOT_WIDTH = static_cast<int>(max_val_char_len) + 3;

    // Calculate the total required width for the console output based on the x-span and slot width.
    int total_console_width = (max_overall_x_inorder - min_overall_x_inorder + 1) * SLOT_WIDTH;
    if (total_console_width < 20) total_console_width = 20; // Ensure a minimum readable width

    // Create a 2D character grid (`std::vector<std::string>`) to "draw" the tree.
    // Each level of nodes takes one row, and the connecting links take an interleaved row.
    // So, total rows = (max_tree_depth + 1 for nodes) + (max_tree_depth for links).
    std::vector<std::string> display_grid((max_tree_depth + 1) * 2, std::string(total_console_width, ' '));

    // --- Step 3: Populate the Grid with Node Values and Links ---
    for (int depth = 0; depth <= max_tree_depth; ++depth) {
        int node_row_idx = depth * 2;       // Row for nodes at the current depth
        int link_row_idx = depth * 2 + 1;   // Row for links connecting to the next depth (below nodes)

        // Sort nodes at the current depth by their in-order x_coordinate.
        // This ensures they are processed and placed from left to right on the console.
        std::sort(nodes_by_depth_storage[depth].begin(), nodes_by_depth_storage[depth].end(),
                  [](const PrintNodeInfo& a, const PrintNodeInfo& b) {
                      return a.x_inorder < b.x_inorder;
                  });

        // Iterate through each node at the current depth.
        for (const auto& p_info : nodes_by_depth_storage[depth]) {
            std::string val_str = std::to_string(p_info.node->val);
            
            // Calculate the central column position for the current node's value string.
            // This translates the relative `x_inorder` to an absolute column on the console.
            int node_center_col = (p_info.x_inorder - min_overall_x_inorder) * SLOT_WIDTH + SLOT_WIDTH / 2;
            
            // Determine the starting column index to print the node's value string,
            // ensuring it's horizontally centered within its allocated slot.
            int node_start_col = node_center_col - (val_str.length() / 2);

            // Adjust `node_start_col` to ensure it doesn't go off the left edge of the grid.
            node_start_col = std::max(0, node_start_col);
            
            // If the node string is too long for the remaining space on the line, truncate it.
            if (node_start_col + val_str.length() > display_grid[node_row_idx].length()) {
                val_str = val_str.substr(0, display_grid[node_row_idx].length() - node_start_col);
            }

            // Place the node's value characters onto the current node row in the grid.
            for (size_t i = 0; i < val_str.length(); ++i) {
                display_grid[node_row_idx][node_start_col + i] = val_str[i];
            }

            // --- Draw links to children on the `link_row_idx` ---
            // Links are only drawn if the current node is not at the maximum depth of the tree,
            // as nodes at the max depth have no children to link to.
            if (depth < max_tree_depth) {
                // If the current node has a left child, draw a '/' character.
                if (p_info.node->left) {
                    // Position the '/' character slightly to the left of the parent's center.
                    int slash_pos = node_center_col - 1;
                    if (slash_pos >= 0 && slash_pos < display_grid[link_row_idx].length()) {
                        display_grid[link_row_idx][slash_pos] = '/';
                    }
                }
                // If the current node has a right child, draw a '\' character.
                if (p_info.node->right) {
                    // Position the '\' character slightly to the right of the parent's center.
                    int backslash_pos = node_center_col + 1;
                    if (backslash_pos >= 0 && backslash_pos < display_grid[link_row_idx].length()) {
                        display_grid[link_row_idx][backslash_pos] = '\\';
                    }
                }
            }
        }
    }

    // --- Step 4: Print the Generated Grid to Console ---
    // Iterate through each row of the `display_grid` and print it.
    for (size_t i = 0; i < display_grid.size(); ++i) {
        // For link rows (odd indices), we might skip printing if there are no links.
        // This prevents printing unnecessary blank lines of spaces.
        if (i % 2 != 0) { // Check if it's a link row (e.g., row 1, 3, 5, etc.)
             bool has_links_or_content = false;
             for (char c : display_grid[i]) {
                 if (c == '/' || c == '\\') { // Check specifically for link characters
                     has_links_or_content = true;
                     break;
                 }
             }
             if (!has_links_or_content) {
                 continue; // If no links on this row, skip it.
             }
        }
        std::cout << display_grid[i] << std::endl;
    }
}


// Helper function to deallocate memory for the tree nodes.
// This prevents memory leaks, especially when running multiple examples.
void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);  // Recursively delete left subtree
        deleteTree(node->right); // Recursively delete right subtree
        delete node;             // Delete the current node
    }
}


int main () {
    vector<int> tests = {1, 2, 3, 4};

    for (int test: tests) {
        Solution sol;
        auto res = sol.generateTrees(test);
        cout << "\n---------------------new test--------------------------\n";
        cout << "Generate trees for input: " << test << "\n";
        for (auto root: res) printTree(root);
    }
}