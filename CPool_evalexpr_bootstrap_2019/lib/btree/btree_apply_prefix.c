/*
** EPITECH PROJECT, 2019
** btree_apply_prefix.c
** File description:
** btree apply prefix
*/

#include <unistd.h>
#include "btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    if (root != NULL) {
        applyf(root->item);
        if (root->left != NULL)
            btree_apply_prefix(root->left, applyf);
        if (root->right != NULL)
            btree_apply_prefix(root->right, applyf);
    }
}
