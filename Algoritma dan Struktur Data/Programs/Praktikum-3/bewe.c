#include "boolean.h"
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    IdxType i;
    int count = 0;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            count++;
        }
    }
    return count;
}

IdxType getFirstIdx(ListStatik l) {
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            return i;
        }
    }
    return IDX_UNDEF;
}

IdxType getLastIdx(ListStatik l) {
    IdxType i;
    for (i = CAPACITY - 1; i >= IDX_MIN; i--) {
        if (ELMT(l, i) != MARK) {
            return i;
        }
    }
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < listLength(l));
}

boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l) {
    IdxType i;
    ElType x;
    CreateListStatik(l);
    i = IDX_MIN;
    scanf("%d", &x);
    while (x != MARK && i < CAPACITY) {
        ELMT(*l, i) = x;
        i++;
        scanf("%d", &x);
    }
}

void printList(ListStatik l) {
    IdxType i;
    if (isEmpty(l)) {
        printf("[]");
    } 
    else {
        printf("[");
        for (i = IDX_MIN; i < listLength(l) - 1; i++) {
            printf("%d, ", ELMT(l, i));
        }
        printf("%d", ELMT(l, i));
    }
    printf("]\n");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l3;
    IdxType i;
    CreateListStatik(&l3);
    if (plus) {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } 
    else {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    IdxType i;
    if (listLength(l1) != listLength(l2)) {
        return false;
    } 
    else {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return false;
            }
        }
        return true;
    }
}

int indexOf(ListStatik l, ElType val) {
    IdxType i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    IdxType i;
    *max = l.contents[IDX_MIN];
    *min = l.contents[IDX_MIN];
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val) {
    IdxType i;
    if (!isFull(*l)) {
        for (i = listLength(*l); i > IDX_MIN; i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, IDX_MIN) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    IdxType i;
    if (!isFull(*l) && isIdxValid(*l, idx)) {
        for (i = listLength(*l); i > idx; i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, idx) = val;
    }
}

void insertLast(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        ELMT(*l, listLength(*l)) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val) {
    IdxType i;
    if (!isEmpty(*l)) {
        *val = ELMT(*l, IDX_MIN);
        for (i = IDX_MIN; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    IdxType i;
    if (!isEmpty(*l) && isIdxValid(*l, idx)) {
        *val = ELMT(*l, idx);
        for (i = idx; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

void deleteLast(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, listLength(*l) - 1);
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

void sortList(ListStatik *l, boolean asc) {
    IdxType i, j;
    ElType temp;
    for (i = IDX_MIN; i < listLength(*l) - 1; i++) {
        for (j = i + 1; j < listLength(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } 
            else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}