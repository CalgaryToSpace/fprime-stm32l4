
#include <Os/TaskId.hpp>

#include "cmsis_os.h"

namespace Os
{
    TaskId::TaskId(void)
    {
        TaskStatus_t taskStatus;
        vTaskGetInfo( NULL, &taskStatus,pdFALSE, eDeleted);
        id = taskStatus.xTaskNumber;
    }
    TaskId::~TaskId(void)
    {
    }
    bool TaskId::operator==(const TaskId& T) const
    {
        return (id == T.id);
    }
    bool TaskId::operator!=(const TaskId& T) const
    {
        return (id != T.id); 
    }
    TaskIdRepr TaskId::getRepr(void) const
    {
        return this->id;
    }
}
