#include <io_utils.h>
#include <stdlib.h>

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

ListNode *CreateNode(int value) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) exit(1);

  node->value = value;
  node->next = NULL;
  return node;
}

void DestroyNode(ListNode **node_ptr) {
  free(*node_ptr);
  *node_ptr = NULL;
}

ListNode *CreateList(int *arr, int len) {
  if (len <= 0) return NULL;

  ListNode *head = CreateNode(arr[0]);
  ListNode *cur = head;
  for (int i = 1; i < len; ++i) {
    cur = cur->next = CreateNode(arr[i]);
  }
  return head;
}

void DestroyList(ListNode **head) {
  if (!head || !(*head)) return;

  ListNode *cur = *head;
  while (cur) {
    ListNode *next = cur->next;
    DestroyNode(&cur);
    cur = next;
  }

  *head = NULL;
}

void InsertNode(ListNode **head, int index, int value) {
  if (!head || index < 0) return;

  ListNode *node = CreateNode(value);
  if (index == 0) {
    node->next = *head;
    *head = node;
  } else {
    if (!(*head)) {
      *head = CreateNode(0);
    }
    ListNode *cur = *head;
    while (--index) {
      if (!cur->next) cur->next = CreateNode(0);
      cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
  }
}

void DeleteNode(ListNode **head, int index) {
  if (!head || !(*head) || index < 0) return;

  if (index == 0) {
    ListNode *new_head = (*head)->next;
    DestroyNode(head);
    *head = new_head;
  } else {
    ListNode *cur = *head;
    while (cur->next && --index) {
      cur = cur->next;
    }
    if (!cur->next) return;
    ListNode *node = cur->next;
    cur->next = node->next;
    DestroyNode(&node);
  }
}

void PrintList(ListNode *head) {
  while (head) {
    printf("%d", head->value);
    head = head->next;
    head ? printf("->") : printf("\n");
  }
}

void FakeDestroyNode(ListNode *node) {
  free(node);
  node = NULL;
}

int main() {
  int arr[] = {0, 1, 2, 3, 4};
  ListNode *head = CreateList(arr, 5);
  PrintList(head);
  InsertNode(&head, 0, 111);
  InsertNode(&head, 10, 333);
  DeleteNode(&head, 0);
  DeleteNode(&head, 5);
  PrintList(head);
  DestroyList(&head);
  PRINT_HEX(head);

  InsertNode(&head, 1, 1);
  PrintList(head);
  DeleteNode(&head, 0);
  DeleteNode(&head, 0);
  PRINT_HEX(head);
  DestroyList(&head);

  return 0;
}