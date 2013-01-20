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
 *      SOM Emitter emitxtm: 2.7
 */

#define PersistentServer_Class_Source
#define SOMMSingleInstance_Class_Source
#include <perserv.xih>
#include <somp.xh>
#include <stdio.h>

#ifdef __IBMC__                                                      
  #pragma linkage(SOMInitModule,system)                              
#endif                                                               

SOMEXTERN void SOMLINK SOMInitModule(long majorVersion,              
                                     long minorVersion,              
                                     string className)               
{                                                                    
   SOM_IgnoreWarning(majorVersion);                                  
   SOM_IgnoreWarning(minorVersion);                                  
   SOM_IgnoreWarning(className);                                     
                                                                     
   PersistentServerNewClass(PersistentServer_MajorVersion, 
                            PersistentServer_MinorVersion);
}

/*
 * Check to see if the persistent object exists
 */

SOM_Scope SOMObject*  SOMLINK getPerStorMgr(PersistentServer *somSelf, 
                                             Environment *ev)
{
    /* PersistentServerData *somThis = PersistentServerGetData(somSelf); */
    SOMPPersistentStorageMgr *psm;
    PersistentServerMethodDebug("PersistentServer","getPerStorMgr");

    psm = new SOMPPersistentStorageMgr();
    return psm;
}

/*
 * Restore a persistent object from its string ID
 */

SOM_Scope boolean  SOMLINK objectExists(PersistentServer *somSelf, 
                                        Environment *ev, string id)
{
    /* PersistentServerData *somThis = PersistentServerGetData(somSelf); */
    SOMPPersistentStorageMgr *psm;   
    SOMPPersistentId         *pid;
    boolean                  rc;
    PersistentServerMethodDebug("PersistentServer","objectExists");

    psm = new SOMPPersistentStorageMgr();
    pid = new SOMPPersistentId();
    pid->somutSetIdString(ev, id);
                                        
    if ( psm->sompObjectExists(ev, pid) )
    {
       rc = TRUE;
    }
    else
    {
       rc = FALSE;
    }
    delete pid;

    return rc;
}

SOM_Scope SOMObject*  SOMLINK restoreObjectFromId(PersistentServer *somSelf, 
                                                  Environment *ev, 
                                                  string id)
{
    /* PersistentServerData *somThis = PersistentServerGetData(somSelf); */
    SOMPPersistentStorageMgr *psm;  
    SOMObject                *obj;
    PersistentServerMethodDebug("PersistentServer","restoreObjectFromId");

    psm = new SOMPPersistentStorageMgr();

    obj = psm->sompRestoreObjectFromIdString(ev,id);

    return obj;
}

SOM_Scope SOMObject*  SOMLINK somdCreateObj(PersistentServer *somSelf, 
                                            Environment *ev, 
                                            Identifier objclass, 
                                            string hints)
{
    /* PersistentServerData *somThis = PersistentServerGetData(somSelf); */
    SOMPPersistentObject *obj;
    SOMPPersistentId     *pid;

    PersistentServerMethodDebug("PersistentServer","somdCreateObj");

    obj = (SOMPPersistentObject *) 
             PersistentServer_parent_SOMDServer_somdCreateObj(somSelf,
                                                              ev,
                                                              objclass,
                                                              NULL);
    if (hints != NULL)  
    {
      //***************************************
      // Assign persistent ID to object
      //***************************************
      pid = new SOMPPersistentId();
      pid->somutSetIdString(ev, hints);
      obj->sompInitGivenId(ev, pid);
    } 

    return obj;
}
