/*
 * SvigroupContainer.hpp
 *
 *  Created on: Apr 22, 2022
 *      Author: madsen
 */

#ifndef SVIGROUPCONTAINER_HPP_
#define SVIGROUPCONTAINER_HPP_

#include "AbstractSviGroup.hpp"

/**
 *  Class with only one purpose - to be a container of items. Does not
 *  contain any functionality for updating items. Just a container.
 *  @see SplitRemoteSviGroupStrategy uses this.
 */
class SviGroupContainer : public AbstractSviGroup{
public:
    SviGroupContainer(bool remote);

    std::string getName(){return "";}

    bool isActive(){return true;}

    void setActive(bool active){}

    void refresh(){};

    void updateOut(){};

    void reset(){};

    bool isRemote(){return remote;}

    std::vector<AbstractSviItem*> getItems(){return items;}

    bool addItem(AbstractSviItem* pSviItem){
        items.push_back(pSviItem);
        return true;
    }

    void clearItems(){
        items.clear();
    }

    ~SviGroupContainer();

private:
    std::vector<AbstractSviItem*> items;

    bool remote;

};

#endif /* SVIGROUPCONTAINER_HPP_ */
