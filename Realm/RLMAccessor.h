////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import "RLMRealm.h"

//
// Accessors Class Creation/Caching
//
@class RLMObjectSchema;

// get accessor classes for an object class - generates classes if not cached
Class RLMAccessorClassForObjectClass(Class objectClass, RLMObjectSchema *schema);
Class RLMStandaloneAccessorClassForObjectClass(Class objectClass, RLMObjectSchema *schema);

//
// Dynamic getters/setters
//
void RLMDynamicValidatedSet(RLMObject *obj, NSString *propName, id val);
id RLMDynamicGet(RLMObject *obj, NSString *propName);

// by property/column
void RLMDynamicSet(RLMObject *obj, RLMProperty *prop, id val, bool enforceUnique, bool tryUpdate, bool create);

//
// Class modification
//

// Replace className method for the given class
void RLMReplaceClassNameMethod(Class accessorClass, NSString *className);

// Replace sharedSchema method for the given class
void RLMReplaceSharedSchemaMethod(Class accessorClass, RLMObjectSchema *schema);
