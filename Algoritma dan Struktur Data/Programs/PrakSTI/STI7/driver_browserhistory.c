#include <stdio.h>
#include "browserhistory.c"

int main()
{
    Stack openedTab;
    Stack history;
    CreateEmpty(&openedTab);
    CreateEmpty(&history);
    infotype temp;

    browserHistoryVisit(&openedTab, &history, "www.google.com");
    browserHistoryVisit(&openedTab, &history, "www.facebook.com");
    browserHistoryVisit(&openedTab, &history, "www.youtube.com");
    browserHistoryVisit(&openedTab, &history, "www.twitter.com");

    currentUrl(&openedTab);
}