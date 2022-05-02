// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
     struct Item {
      T value;
      Item* next;
     };
     Item* head, *tail;
     Item *create(T value) {
         Item* item = new Item;
         item -> value = value;
         item -> next = nullptr;
         return item;
     }
 public:
     TPQueue() : head(nullptr), tail(nullptr) {}
     void push(const T& value) {
         if (tail && head) {
             Item* temp = head;
             if (temp->value.prior < value.prior) {
                 temp = create(value);
                 temp->next = head;
                 head = temp;
             } else {
                 while (temp->next) {
                     if (temp->next->value.prior < value.prior) {
                         Item* item = create(value);
                         item->next = temp->next;
                         temp->next = item;
                         break;
                     } else {
                         temp = temp->next;
                     }
                 }
             }
             if (!temp->next) {
                 tail->next = create(value);
                 tail = tail->next;
             }
         } else {
             head = create(value);
             tail = head;
         }
     }
     T pop() {
         Item* temp = head->next;
         T value = head->value;
         delete head; head = temp; return value;
     }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
