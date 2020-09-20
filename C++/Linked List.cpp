struct ListNode {
	ListNode *prev, *next;
	int value;
};

struct LinkedList {
	ListNode *front, *back;

	void addFront(LinkedList& l) {
		l.back->next = front;
		front->prev = l.back;
		front = l.front;
	}

	void addFront(ListNode* l) {
		front->prev = l;
		l->next = front;
		front = l;
	}

	void addBack(LinkedList& l) {
		back->next = l.front;
		l.front->prev = back;
		back = l.back;
	}

	void addBack(ListNode* l) {
		back->next = l;
		l->prev = back;
		back = back->next;
	}

	void print() {
		ListNode* temp = front;
		while (temp != nullptr) {
			cout << temp->value << ' ';
			temp = temp->next;
		}
		cout << '\n';
	}
};
