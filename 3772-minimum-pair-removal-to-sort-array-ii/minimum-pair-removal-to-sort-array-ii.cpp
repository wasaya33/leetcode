class Solution {
public:
    struct Node {
        long long val;
        int id;
        Node* prev;
        Node* next;
        bool alive;
        Node(long long v, int i): val(v), id(i), prev(nullptr), next(nullptr), alive(true) {}
    };

    struct Item {
        long long sum;
        int leftId;      // tie-break (acts like leftmost among still-alive nodes by original order)
        Node* left;
        bool operator>(const Item& other) const {
            if (sum != other.sum) return sum > other.sum;
            return leftId > other.leftId;
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        vector<Node*> nodes(n);
        for (int i = 0; i < n; ++i) nodes[i] = new Node(nums[i], i);
        for (int i = 0; i < n; ++i) {
            if (i) nodes[i]->prev = nodes[i - 1];
            if (i + 1 < n) nodes[i]->next = nodes[i + 1];
        }

        auto badEdge = [&](Node* a, Node* b) -> int {
            if (!a || !b || !a->alive || !b->alive) return 0;
            return a->val > b->val;
        };

        long long bad = 0;
        for (Node* cur = nodes[0]; cur && cur->next; cur = cur->next)
            bad += badEdge(cur, cur->next);

        priority_queue<Item, vector<Item>, greater<Item>> pq;
        for (Node* cur = nodes[0]; cur && cur->next; cur = cur->next)
            pq.push({cur->val + cur->next->val, cur->id, cur});

        int ops = 0;

        while (bad > 0) {
            Item it = pq.top(); pq.pop();
            Node* a = it.left;
            if (!a || !a->alive || !a->next || !a->next->alive) continue;
            if (a->val + a->next->val != it.sum) continue;

            Node* b = a->next;
            Node* p = a->prev;
            Node* q = b->next;

            bad -= badEdge(p, a);
            bad -= badEdge(a, b);
            bad -= badEdge(b, q);

            a->val += b->val;
            b->alive = false;

            a->next = q;
            if (q) q->prev = a;

            bad += badEdge(p, a);
            bad += badEdge(a, q);

            if (p) pq.push({p->val + a->val, p->id, p});
            if (a->next) pq.push({a->val + a->next->val, a->id, a});

            ++ops;
        }

        for (auto* nd : nodes) delete nd;
        return ops;
    }
};
