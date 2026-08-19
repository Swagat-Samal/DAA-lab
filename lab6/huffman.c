#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Node
{
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data, int freq)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void sortNodes(struct Node *nodes[], int n)
{
    int i, j;
    struct Node *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (nodes[j]->freq > nodes[j + 1]->freq)
            {
                temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

struct Node *buildHuffmanTree(char alphabet[], int freq[], int n)
{
    struct Node *nodes[MAX];
    struct Node *left, *right, *newNode;
    int i, size = n;

    for (i = 0; i < n; i++)
        nodes[i] = createNode(alphabet[i], freq[i]);

    while (size > 1)
    {
        sortNodes(nodes, size);

        left = nodes[0];
        right = nodes[1];

        newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;

        for (i = 1; i < size - 1; i++)
            nodes[i] = nodes[i + 1];

        size--;
    }

    return nodes[0];
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        if (root->data != '$')
            printf("%c ", root->data);

        inorder(root->right);
    }
}

int main()
{
    int n, i;
    char alphabet[MAX];
    int freq[MAX];

    struct Node *root;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    printf("Enter the alphabets: ");
    for (i = 0; i < n; i++)
        scanf(" %c", &alphabet[i]);

    printf("Enter the frequencies: ");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    root = buildHuffmanTree(alphabet, freq, n);

    printf("\nIn-order traversal of the tree (Huffman): ");
    inorder(root);

    printf("\n");

    return 0;
}
