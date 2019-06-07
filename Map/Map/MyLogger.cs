using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using log4net;

namespace Map
{
    public class MyLogger
    {
        private static MyLogger instance;

        private static ILog logger = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public static MyLogger getInstance()
        {
            if (instance == null)
            {
                instance = new MyLogger();
            }

            return instance;
        }

        public void logDebug (String message)
        {
            logger.Debug(message);
        }
    }
}
