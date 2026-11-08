// 1828. Queries on Number of Points Inside a Circle  [Medium]

struct KDTree{
    int x, y;
    KDTree *left, *right;

    KDTree(int x, int y){
        this->x = x;
        this->y = y;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:

    int getCountOfPoints(int cx, int cy, int radius, KDTree *root, int depth){
        if(root == nullptr) return 0;

        //Treat root as coorinates to figure out if the coordinates lie in/on the circle
        int dx = root->x - cx;
        int dy = root->y - cy;
        int count = (dx*dx + dy*dy <= radius*radius);

        if(depth%2==0){
            if(cx - radius <= root->x){
                count += getCountOfPoints(cx, cy, radius, root->left, depth+1);
            }
            if(cx + radius >= root->x){
                count += getCountOfPoints(cx, cy, radius, root->right, depth+1);
            }
        }
        else{
            if(cy - radius <= root->y){
                count += getCountOfPoints(cx, cy, radius, root->left, depth+1);
            }
            if(cy + radius >= root->y){
                count += getCountOfPoints(cx, cy, radius, root->right, depth+1);
            }
        }
        return count;
    }

    KDTree *add(KDTree *root, KDTree *node, int depth){
        if(root == nullptr) return node;
        if(depth%2 == 0){
            if(root->x > node->x){
                root->left = add(root->left, node, depth+1);
            }
            else root->right = add(root->right, node, depth+1); 
        }
        else{
            if(root->y > node->y){
                root->left = add(root->left, node, depth+1);
            }
            else root->right = add(root->right, node, depth+1);
        }
        return root;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        KDTree *root = new KDTree(points[0][0], points[0][1]);
        for(int i = 1 ; i < points.size() ; i++){
            root = add(root, new KDTree(points[i][0], points[i][1]), 0);
        }

        for(int i = 0 ; i < queries.size() ; i++){
            ans.push_back(getCountOfPoints(queries[i][0], queries[i][1], queries[i][2], root, 0));
        }
        return ans;
    }
};

//if we want to search in an optimal way, we have to use binary search.
//so for doing binary search we would need points array to be sorted, and ranges of x and y
//but there is a way to find ranges which lies inside circle and bounded square, but we can range in circle which is
//range of circle = (Range of bounded square) - (range outside circle but within bounded sqaure)-> this is impossible
//so rather than that we can find range of queries(coordinates) which will be outside the circle always
// total - no of coordinates outside the circle = no of coordinates inside the circle
//this approach is for optimal solution, the suboptimal way is still comparing the ranges with each coordinates.