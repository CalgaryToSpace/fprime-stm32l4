#include <Os/Task.hpp>
#include <Fw/Types/Assert.hpp>
#include <stdlib.h>
#include <string.h>

#include "cmsis_os.h"

namespace Os {
    Task::Task() : m_handle(0), m_identifier(0), m_affinity(-1), m_started(false), m_suspendedOnPurpose(false), m_routineWrapper() {
    }

    Task::TaskStatus Task::start(const Fw::StringBase &name, taskRoutine routine, void* arg, NATIVE_UINT_TYPE priority, NATIVE_UINT_TYPE stackSize, NATIVE_UINT_TYPE cpuAffinity, NATIVE_UINT_TYPE identifier) {
    TaskHandle_t xHandle;
        this->m_name = "TP_";
        this->m_name += name;
        this->m_identifier = identifier;
        Task::TaskStatus tStat = TASK_OK;
        int basetype;

        basetype = xTaskCreate(routine, (char*)this->m_name.toChar(), stackSize, arg, priority, &xHandle );
        if (basetype !=1){
            tStat = TASK_INVALID_PARAMS;
        }
        else{
            this->m_handle = (POINTER_CAST)xHandle;
        }
        return tStat;
    }

    Task::TaskStatus Task::delay(NATIVE_UINT_TYPE milliseconds)
    {
        vTaskDelay(milliseconds);

        return TASK_OK; // for coverage analysis

    }


    Task::~Task() {
        // If a registry has been registered, remove task
        if (Task::s_taskRegistry) {
            Task::s_taskRegistry->removeTask(this);
        }

    }

    // Note: not implemented for Posix threads. Must be manually done using a mutex or other blocking construct as there
    // is not top-level pthreads support for suspend and resume.

    void Task::suspend(bool onPurpose) {
        FW_ASSERT(0);
    }

    void Task::resume(void) {
        FW_ASSERT(0);
    }

    bool Task::isSuspended(void) {
        FW_ASSERT(0);
        return false;
    }

    TaskId Task::getOsIdentifier(void) {
        TaskId T;
        return T;
    }

    Task::TaskStatus Task::join(void **value_ptr) {
        FW_ASSERT(0);
        return TASK_OK;
    }
    
}
