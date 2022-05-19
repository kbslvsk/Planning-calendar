/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#include "CViewManager.h"

unique_ptr<CView> CViewManager::findView(string wantedView) const {
    auto search = views.find( wantedView );

    if ( search == views.end() ) {
        return nullptr;
    }

    return search->second->Clone();

}

CViewManager::CViewManager()
{
    views.emplace("daily"  , make_unique<CDailyView>());
    views.emplace("weekly" , make_unique<CWeeklyView>());
    views.emplace("monthly", make_unique<CMonthlyView>());


}

