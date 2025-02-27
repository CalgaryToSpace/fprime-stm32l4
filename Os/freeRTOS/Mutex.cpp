#include <Os/Mutex.hpp>
#include <Fw/Types/Assert.hpp>

#include "cmsis_os.h"
#include "semphr.h"

namespace Os {
    
    Mutex::Mutex(void) {
        SemaphoreHandle_t handle;

        handle = xSemaphoreCreateMutex();
        
        this->m_handle = (POINTER_CAST) handle;
    }
    
    Mutex::~Mutex(void) {
        vSemaphoreDelete(this->m_handle);
    }
    
    void Mutex::lock(void) {
        NATIVE_INT_TYPE stat = xSemaphoreTake( (SemaphoreHandle_t)this->m_handle, ( TickType_t ) 10 );
        FW_ASSERT(stat == pdTRUE,stat);
    }

    void Mutex::unLock(void) {
        NATIVE_INT_TYPE stat = xSemaphoreGive( this->m_handle);
        FW_ASSERT(stat == pdTRUE,stat);
    }
            
}


