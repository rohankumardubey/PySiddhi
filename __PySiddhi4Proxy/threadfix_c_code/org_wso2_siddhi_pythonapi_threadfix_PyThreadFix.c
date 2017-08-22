/*
 * Copyright (c) 2017, WSO2 Inc. (http://www.wso2.org) All Rights Reserved.
 *
 * WSO2 Inc. licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <jni.h>
#include <stdio.h>

#include <boost/python.hpp>

#include "org_wso2_siddhi_pythonapi_threadfix_PyThreadFix.h"

JNIEXPORT void JNICALL Java_org_wso2_siddhi_pythonapi_threadfix_PyThreadFix_fixThread(JNIEnv *env, jobject thisObj)
{
   PyGILState_STATE state;

   PyInterpreterState *istate = PyInterpreterState_Head();
   PyThreadState_New(istate);

   state = PyGILState_Ensure();
   PyGILState_Release(state);

   return;
}
