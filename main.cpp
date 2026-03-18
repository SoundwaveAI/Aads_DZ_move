#include <cstddef>

template <class T>
struct List {
    T val;
    List<T>* next;
};

template <class T>
struct Vec {
    T* data;
    size_t s, cap;
};

template <class T>
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k) {
  if (k == 0) {
    return {nullptr, 0, 0};
  }

  size_t total = 0;
  for (size_t i = 0; i < v.s; ++i) {
    List<T>* curr = v.data[i];
    while (curr) {
      total++;
      curr = curr->next;
    }
  }

  Vec< List<T>* > res = {nullptr, 0, 0};
  if (total == 0) {
    return res;
  }

  size_t num_lists = (total + k - 1) / k;
  res.data = new List<T>*[num_lists]();
  res.s = num_lists;
  res.cap = num_lists;

  size_t res_idx = 0;
  size_t count = 0;
  List<T>* head = nullptr;
  List<T>* tail = nullptr;

  for (size_t i = 0; i < v.s; ++i) {
    List<T>* curr = v.data[i];
    v.data[i] = nullptr;
    while (curr) {
      List<T>* next_node = curr->next;
      curr->next = nullptr;

      if (!head) {
        head = curr;
        tail = curr;
      } else {
        tail->next = curr;
        tail = curr;
      }
      count++;

      if (count == k) {
        res.data[res_idx++] = head;
        head = nullptr;
        tail = nullptr;
        count = 0;
      }
      curr = next_node;
    }
  }
  if (head) {
      res.data[res_idx] = head;
  }

  return res;
}
