/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/

#include"lib/my/btree/btree.h"
#include<stdio.h>

char *infiniadd(char *op1, char *op2);
char *infinimul(char *op1, char *op2);
char *infinidiv(char *op1, char *op2);
char *infinimod(char *op1, char *op2);

void *pologne(void *op1, void *op2, void *c)
{
    char *res;
    switch ((char)c)
    {
    case '+':
        res = infiniadd((char *)op1, (char *)op2); 
        break;
    /*case '-':
        res = infiniadd((char *)op1, (char *)op2); 
        break;*/
    case '*':
        res = infinimul((char *)op1, (char *)op2); 
        break;
    case '/':
        res = infinidiv((char *)op1, (char *)op2); 
        break;
    case '%':
        res = infinimod((char *)op1, (char *)op2); 
        break;    
    default:
        write(2, "Invalid operand used in parser !", 32);
        break;
    }
    return res;
}



char *parser(btree_t **base)
{
    btree_t *root = *base;
    if (root == NULL) //Cas d'erreur
        return NULL;
    if (root->left == NULL && root->right == NULL) //Cas final (où les enfants left et rights sont nulles)
        return (char *)root->item;
    if (root->left->left == root->right->left ==
        root->left->right == root->right->right == NULL) { //Cas où on détecte un node avec deux feuilles(qui n'ont pas d'enfant)
        root->item = pologne(root->left->item, root->right->item, root->item);// Dans ce cas là on applique la methode polonaise
        free(root->left);// et on free les enfants/feuilles qui sont utilisés donc maintenant vide
        free(root->right);
        }
    else { //si les deux enfants de la node ne sont pas des feuilles il faut appliquer la fonction sur eux
        if (root->left->left != NULL && root->left->right != NULL)
            parser(root->left);
        if (root->right->left != NULL && root->right->right != NULL)
            parser(root->right);
    }
}
/*
#include"lib/my/btree/btree_create_node.c"
#include<stddef.h>
int main(int argc, char *argv[])
{
    btree_t *root;
    root = btree_create_node((void *)'+');
    root->left = btree_create_node((void *)'+');    
    root->left->left = btree_create_node((void *)"8");
    root->left->right = btree_create_node((void *)"8");
    root->right = btree_create_node((void *)'+');
    root->right->left = btree_create_node((void *)"2");
    root->right->right = btree_create_node((void *)"6");

    printf(parser(&root));
    return 0;
}*/
