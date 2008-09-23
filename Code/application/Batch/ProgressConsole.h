/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __PROGRESSCONSOLE_H
#define __PROGRESSCONSOLE_H

#include "Progress.h"
#include "SubjectImp.h"

#include <string>

/**
 * Progress reporting interface.
 *
 * This object serves as a collector of progress/activity notifications.
 * Whenever it receives an update, it notifies any clients that might
 * have registered with the object so they can interrogate what the
 * change was and render/react to it as appropriate.
 */
class ProgressConsole : public Progress, SubjectImp
{
public:
   ProgressConsole();

   /**
    *  Output final status to console.
    *
    *  The method ProgressConsole() outputs the final display status to the console.  It 
    *  completes the current status line and advances to the next line.
    */
   virtual ~ProgressConsole();

   /**
    *  Indicate that some activity has taken place.
    *
    *  @param   text
    *           Message indicating the nature of the activity being reported.
    *  @param   percent
    *           For partial completion status changes, this figure represents
    *           what percent (0-100) of the activity has cumulatively been
    *           completed.
    *  @param   state
    *           The type of message.  The following are valid values 
    *           for state (NORMAL, WARNING, ERRORS, and ABORT).
    *<pre>
    *         Level        Description
    *         ==========   ========================================================
    *         NORMAL       Normal brief status messages.
    *         WARNING      Warning message showing some minor error was detected.
    *         ERRORS       Error has occurred in the process.  
    *         ABORT        A message showing the process was aborted.
    *</pre>  
    */
   void updateProgress(const std::string& text, int percent, ReportingLevel state);

   /**
    *  Report the activity that has taken place.
    *
    *  @param   text
    *           Message indicating the nature of the activity being reported.
    *  @param   percent
    *           For partial completion status changes, this figure represents
    *           what percent (0-100) of the activity has cumulatively been
    *           completed.
    *  @param   state
    *           Reporting level granularity, allowing clients to filter out
    *           activity changes they are not interested in. For example,
    *           most clients would ignore debugging mode notifications.
    */
   void getProgress(std::string& text, int& percent, ReportingLevel& state) const;

   // 
   // Inherited from TypeAwareObject
   //

   /** 
    *  Return a string containing the class name. Must be implemented
    *  by all subclasses.
    *
    *  @return  A string containing the name of the class.
    */
   const std::string& getObjectType() const;

   /**
    *  Compare if incoming argument string matches either the object's
    *  true class name or one of its parent (derived-from) class names.
    *
    *  @param   className
    *           Name of the class that is to be searched for in the object's
    *           inheritance hierarchy.
    *
    *  @return  True if the object's class, or something it can safely be
    *           cast to, matches the incoming argument.
    */
   bool isKindOf(const std::string& className) const;

   // 
   // Inherited from Subject
   //

   /**
    *  Allow another object to register an interest in this object.
    *
    *  @param   watcher
    *           Pointer to another object whose update method is to be
    *           called when this object experiences a mutation.
    */

   /**
    *  Allow a former subscriber to be dropped from the list of objects
    *  to be notified when this object mutates.
    *
    *  @param   ignorer
    *           Pointer to the object to be removed from the subscription
    *           list.
    */

   bool attach(const std::string &signal, const Slot &slot)
   {
      return SubjectImp::attach(signal, slot);
   }
   bool detach(const std::string &signal, const Slot &slot)
   {
      return SubjectImp::detach(signal, slot);
   }


private:
   std::string mMessage;
   int mPercentDone;
   ReportingLevel mReportLevel;
};

#endif   // __PROGRESSCONSOLE_H
