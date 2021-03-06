/**************************************************************************
 *
 *  Copyright 1994, Christina Lau
 *
 *  This file is part of Object-Orientated Programming using SOM and DSOM.
 *
 *  This program is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or (at your
 *  option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */


/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitxtm: somc/smmain.c
 */

#define FlyingObject_Class_Source
#define MetaFlyingObject_Class_Source
#include <fly.xih>


SOM_Scope void  SOMLINK somInit(FlyingObject *somSelf)
{
    FlyingObjectData *somThis = FlyingObjectGetData(somSelf);
    FlyingObjectMethodDebug("FlyingObject","somInit");

    somThis->speed = 10;
    FlyingObject_parent_SOMObject_somInit(somSelf);
}


SOM_Scope FlyingObject*  SOMLINK createFlyingObject(MetaFlyingObject *somSelf, 
                                                    Environment *ev, 
                                                    short speed)
{
    FlyingObject *flyobj;

    MetaFlyingObjectData *somThis = MetaFlyingObjectGetData(somSelf); 
    MetaFlyingObjectMethodDebug("MetaFlyingObject","createFlyingObject");

    flyobj = somSelf->somNew();
    flyobj->_set_speed(ev,speed);

    (somThis->count)++;
    return flyobj;
}

