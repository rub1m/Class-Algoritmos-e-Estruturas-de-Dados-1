/* SPELLBOOK.H
#ifndef SPELLBOOK_H
#define SPELLBOOK_H

typedef struct {
    int id;
    char name[50];
    int mana_cost;
} Spell;
typedef struct Node {
    Spell spell;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} Spellbook;

Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif
*/

/* SPELLBOOK.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

Spellbook* create_spellbook() {
    Spellbook* book = (Spellbook*)malloc(sizeof(Spellbook));
    book->head = NULL;
    return book;
}

void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->spell.id = id;
    strncpy(newNode->spell.name, name, 49);
    newNode->spell.mana_cost = mana_cost;
    newNode->next = NULL;
    if (book->head == NULL) {
        book->head = newNode;
    } else {
        Node* temp = book->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void display_spellbook(Spellbook* book) {
    Node* current = book->head;
    while (current != NULL) {
        printf("ID: [%d], Feitiço: [%s], Custo de Mana: [%d]\n", 
                current->spell.id, current->spell.name, current->spell.mana_cost);
        current = current->next;
    }
}
void destroy_spellbook(Spellbook* book) {
    Node* current = book->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(book);
}
*/
// MAIN.c
#include "spellbook.h"

int main() {
    Spellbook* meuGrimorio = create_spellbook();

    add_spell(meuGrimorio, 1, "Bola de Fogo", 20);
    add_spell(meuGrimorio, 2, "Escudo Arcano", 15);
    add_spell(meuGrimorio, 3, "Raio Congelante", 25);

    display_spellbook(meuGrimorio);

    destroy_spellbook(meuGrimorio);
    return 0;
}
